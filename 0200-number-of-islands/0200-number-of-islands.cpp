class Solution {
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
public:
    bool valid(int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m)
           return false;
        return true;   
    }
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j,vector<vector<bool>>& visit){
        visit[i][j]=1;
        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(row,col,n,m)&&grid[row][col]=='1'&& visit[row][col]==0)
               dfs(grid,n,m,row,col,visit);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        int i,j;
        vector<vector<bool>>visit(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            visit[i]=t;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'&& visit[i][j]==0){
                    dfs(grid,n,m,i,j,visit);
                    res++;
                }
            }
        }
        return res;
    }
};