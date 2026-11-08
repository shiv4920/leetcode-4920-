
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        visited[i][j] = true;

        int count = 1;

        // Explore all servers in the same row
        for(int col = 0; col < n; col++) {
            if(grid[i][col] == 1 && !visited[i][col]) {
                count += dfs(grid, i, col);
            }
        }

        // Explore all servers in the same column
        for(int row = 0; row < m; row++) {
            if(grid[row][j] == 1 && !visited[row][j]) {
                count += dfs(grid, row, j);
            }
        }

        return count;
    }

    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {
                    int cnt = dfs(grid, i, j);

                    if(cnt > 1) {
                        ans += cnt;
                    }
                }
            }
        }

        return ans;
    }
};
