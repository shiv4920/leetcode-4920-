class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.rbegin(),nums.rend());
        long long sum=0;
        long long diff=0;
        for(int i=0;i<ceil(n/2.0);i++){
            sum+=nums[i];
        }
        for(int i=ceil(n/2.0);i<n;i++){
            diff+=nums[i];
        }
        
        return (sum-diff);
    }
};