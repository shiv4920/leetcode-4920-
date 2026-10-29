#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
private:
    int n;
    string s_copy;
    vector<vector<int>> adj;
    int LOGN;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> tin, tout;
    int timer;
    vector<int> root_mask;
    vector<int> euler_val;
    vector<int> bit;

    void dfs(int u, int p, int d, int current_mask) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOGN; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        tin[u] = ++timer;
        int char_bit = 1 << (s_copy[u] - 'a');
        current_mask ^= char_bit;
        root_mask[u] = current_mask;
        euler_val[tin[u]] = current_mask;

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, current_mask);
            }
        }
        tout[u] = timer;
    }

    void bit_point_update(int idx, int val) {
        int sz = (int)bit.size();
        for (; idx < sz; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void bit_range_update(int l, int r, int val) {
        bit_point_update(l, val);
        bit_point_update(r + 1, val);
    }

    int bit_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        for (int i = LOGN - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = LOGN - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->s_copy = s;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        LOGN = 17;
        up.assign(n, vector<int>(LOGN, 0));
        depth.resize(n);
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        root_mask.resize(n);
        euler_val.resize(n + 1, 0);

        dfs(0, 0, 0, 0);

        // Build Difference Array for BIT range updates
        bit.assign(n + 2, 0);
        vector<int> diff(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            diff[i] ^= euler_val[i];
            if (i + 1 <= n + 1) {
                diff[i + 1] ^= euler_val[i];
            }
        }

        for (int i = 1; i <= n + 1; ++i) {
            bit[i] = diff[i];
        }

        for (int i = 1; i <= n + 1; ++i) {
            int p = i + (i & -i);
            if (p <= n + 1) {
                bit[p] ^= bit[i];
            }
        }

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                if (s_copy[u] != c) {
                    int old_bit = 1 << (s_copy[u] - 'a');
                    int new_bit = 1 << (c - 'a');
                    int diff_val = old_bit ^ new_bit;
                    s_copy[u] = c;
                    bit_range_update(tin[u], tout[u], diff_val);
                }
            } else {
                int u, v;
                ss >> u >> v;
                int lca = get_lca(u, v);
                int mask_u = bit_query(tin[u]);
                int mask_v = bit_query(tin[v]);

                int lca_char_bit = 1 << (s_copy[lca] - 'a');
                int path_mask = mask_u ^ mask_v ^ lca_char_bit;

                // Check if path_mask has at most one bit set
                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }
        return ans;
    }
};