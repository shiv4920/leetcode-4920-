
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute cost for every substring
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int mini = INT_MAX;

                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = len / d;

                    for (int r = 0; r < d; r++) {

                        for (int t = 0; t < groups / 2; t++) {

                            int left = i + r + t * d;
                            int right = i + r + (groups - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    mini = min(mini, changes);
                }

                cost[i][j] = mini;
            }
        }

        // DP
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                for (int p = 2 * (parts - 1); p <= i - 2; p++) {

                    if (dp[p][parts - 1] == INF) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
