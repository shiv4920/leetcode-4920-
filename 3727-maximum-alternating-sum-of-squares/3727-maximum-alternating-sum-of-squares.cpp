class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        long long sum=0;
        long long diff=0;
        for(int i=0;i<n/2;i++){
            diff+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            sum+=nums[i];
        }
        return (sum-diff);
    }
};