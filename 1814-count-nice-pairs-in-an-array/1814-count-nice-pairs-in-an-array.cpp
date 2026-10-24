class Solution {
    int Mod=1e9+7;
public:
    int rev(int num){
        int rev=0;
        while(num>0){
            int n=num%10;
            rev=rev*10+n;
            num/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp;

       for(int i=0;i<n;i++){
        mp[nums[i]-rev(nums[i])]++;
       } 

       long long count=0;
       for(auto x:mp){
        if(x.second>1){
            long long p=x.second;
            count=(count+p*(p-1)/2)%Mod;
        }
       }
       return count;
    }
};