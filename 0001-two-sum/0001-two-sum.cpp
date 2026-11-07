class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
           mp.push_back({nums[i],i});
        }
        sort(mp.begin(),mp.end());
        int i=0,j=n-1;
        while(i<j){
          int sum=mp[i].first+mp[j].first;
            if(sum==target){
                return {mp[i].second,mp[j].second};
            }else if(sum<target){
                i++;
            }else{
                j--;
            }
        }
        return {};
    }
};