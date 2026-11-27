class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> free(n, 0);

        // Calculate free copies for each item
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int bonus = free[i];

            vector<int> prev = dp;

            for (int r = 0; r < price && r <= budget; r++) {
                int best = INT_MIN;

                for (int b = r; b <= budget; b += price) {
                    int t = (b - r) / price;

                    if (t >= 1) {
                        int q = b - price;
                        int s = t - 1;

                        best = max(best, prev[q] - s);

                        dp[b] = max(dp[b], best + t + bonus);
                    }
                }
            }
        }

        return dp[budget];
    }
};