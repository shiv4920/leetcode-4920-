class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>ans(n);
        for(int i=0;i<n;i++){
            int sum=0;
            int num=nums[i];
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            ans[i]={sum,nums[i]};
        }
        sort(ans.begin(),ans.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int acc=ans[i].second;
            int curr=nums[i];
            if(nums[i]==ans[i].second)continue;
            int idx=mp[acc];
            swap(nums[i],nums[idx]);
            mp[curr]=idx;
            mp[acc]=i;
            count++;
        }
        return count;
    }
};