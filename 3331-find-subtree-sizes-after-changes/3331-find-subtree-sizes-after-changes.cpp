
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<vector<int>> st(26);
        vector<vector<int>> newTree(n);

        function<void(int)> dfs = [&](int node) {

            int ch = s[node] - 'a';

            int newParent = node;

            if (!st[ch].empty()) {
                newParent = st[ch].back();
            }
            else if (node != 0) {
                newParent = parent[node];
            }

            if (node != 0) {
                newTree[newParent].push_back(node);
            }

            st[ch].push_back(node);

            for (int child : adj[node]) {
                dfs(child);
            }

            st[ch].pop_back();
        };

        dfs(0);

        vector<int> ans(n, 1);

        function<int(int)> dfs2 = [&](int node) {
            for (int child : newTree[node]) {
                ans[node] += dfs2(child);
            }

            return ans[node];
        };

        dfs2(0);

        return ans;
    }
};
