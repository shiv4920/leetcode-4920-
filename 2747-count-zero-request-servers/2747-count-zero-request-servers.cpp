
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
        [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = queries.size();

        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int i = 0, j = 0;
        int active = 0;

        for(auto &query : q) {

            int t = query.first;
            int idx = query.second;

            // Add logs up to current query time
            while(j < logs.size() && logs[j][1] <= t) {
                int id = logs[j][0];

                if(freq[id] == 0)
                    active++;

                freq[id]++;
                j++;
            }

            // Remove logs outside the time window
            while(i < j && logs[i][1] < t - x) {
                int id = logs[i][0];

                freq[id]--;

                if(freq[id] == 0)
                    active--;

                i++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
