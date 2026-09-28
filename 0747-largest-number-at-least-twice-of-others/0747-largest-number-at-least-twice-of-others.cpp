class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int idx=0;
        for(int i=0;i<n;i++){
          if(nums[i]>maxi){
            maxi=nums[i];
            idx=i;
          }
        }
        for(int i=0;i<n;i++){
            if(2*nums[i]>maxi&&nums[i]!=maxi){
                return -1;
            }
        }
        return idx;
    }
};