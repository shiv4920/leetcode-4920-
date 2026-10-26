class Solution {
public:
    int n,m;
    vector<pair<int,int>>loc={{0,-1},{0,1},{1,0},{-1,0}};
    long long dfs(int i,int j,vector<vector<int>>&grid){
        long long sum=grid[i][j];
        grid[i][j]=0;
        for(auto dir:loc){
            int i_=i+dir.first;
            int j_=j+dir.second;
            if(i_>=0&&i_<n&&j_>=0&&j_<m&&grid[i_][j_]>0){
                sum+=dfs(i_,j_,grid);
            }
        }
    return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    long long  sum=dfs(i,j,grid);
                    if(sum%k==0){
                      count++;
                    }
                }
            }
        }
        return count;
    }
};