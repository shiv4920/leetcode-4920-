
class Solution {
public:
    int n, m;
    vector<pair<int,int>> loc = {{0,-1}, {0,1}, {1,0}, {-1,0}};

    long long bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({i, j});

        long long sum = grid[i][j];
        grid[i][j] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : loc) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    grid[nx][ny] > 0) {
                    sum += grid[nx][ny];
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        if (n == 0) return 0;

        m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
