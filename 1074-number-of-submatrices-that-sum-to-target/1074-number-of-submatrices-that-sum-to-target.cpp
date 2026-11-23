class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
           for(int j=1;j<m;j++){
             matrix[i][j]+=matrix[i][j-1];
           }
        }
        int count=0;
        for(int left=0;left<m;left++){
            for(int right=left;right<m;right++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int cumsum=0;
                for(int i=0;i<n;i++){
                cumsum+=matrix[i][right]-(left>0?matrix[i][left-1]:0);
                if(mp.find(cumsum-target)!=mp.end()){
                    count+=mp[cumsum-target];
                }
                mp[cumsum]++;
                }
            }
        }
        return count;
    }
};