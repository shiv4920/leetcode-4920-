class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        priority_queue<long long>q;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        }
        int i=0;
        long long sum=0;
        long long diff=0;
        while(!q.empty()){
            if(i<ceil(n/2.0)){
                sum+=q.top();
                q.pop();
                i++;
            }else{
                diff+=q.top();
                q.pop();
                i++;
            }
        }
        return (sum-diff);
    }
};