class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
         res[0]=nums[0];
         int sum=0;
        for(int i=1;i<n;i++){
            sum+=nums[i-1];
          res[i]=nums[i]+sum;
        }
        return res;
    }
};