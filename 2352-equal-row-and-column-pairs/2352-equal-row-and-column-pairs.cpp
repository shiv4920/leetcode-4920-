class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int>mp;
        for(int r=0;r<n;r++){
            vector<int>ans(n);
            for(int i=0;i<n;i++){
            ans[i]=grid[r][i];
            }
            mp[ans]++;
        }

        int x=0;
        for(int c=0;c<n;c++){
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                temp[i]=grid[i][c];
            }
                x+=mp[temp];
        }
        return x;
    }
};