class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini=min(mini,matrix[i][j]);
            }
            for(int j=0;j<m;j++){
                int maxi=INT_MIN;
                for(int i=0;i<n;i++){
                    maxi=max(maxi,matrix[i][j]);
                }
            if(matrix[i][j] == mini && matrix[i][j] == maxi) {
                    ans.push_back(mini);
                }
            }
        }
    return ans;
    }
};