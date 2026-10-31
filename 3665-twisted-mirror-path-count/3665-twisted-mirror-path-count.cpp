class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long r = right[i][j];
                long long d = down[i][j];

                // Starting position
                if (i == 0 && j == 0) {
                    r = 0;
                    d = 0;

                    // Initially, robot can move right or down
                    if (grid[i][j] == 0) {
                        right[i][j] = 0;
                        down[i][j] = 0;

                        if (j + 1 < n)
                            right[i][j + 1] = (right[i][j + 1] + 1) % MOD;

                        if (i + 1 < m)
                            down[i + 1][j] = (down[i + 1][j] + 1) % MOD;
                    }

                    continue;
                }

                // Destination
                if (i == m - 1 && j == n - 1) {
                    if (grid[i][j] == 0) {
                        ans = (r + d) % MOD;
                    }
                    continue;
                }

                if (grid[i][j] == 0) {

                    // Empty cell: can move right or down
                    long long ways = (r + d) % MOD;

                    if (j + 1 < n)
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;

                    if (i + 1 < m)
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                }
                else {

                    // Mirror cell

                    // Entered from left -> move down
                    if (i + 1 < m)
                        down[i + 1][j] =
                            (down[i + 1][j] + r) % MOD;

                    // Entered from above -> move right
                    if (j + 1 < n)
                        right[i][j + 1] =
                            (right[i][j + 1] + d) % MOD;
                }
            }
        }

        return ans;
    }
};