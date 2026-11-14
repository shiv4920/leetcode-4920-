class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int k=l;k<=r;k++){
        int  sum=0;    
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1==k){
              if(sum>0){  
              mini=min(mini,sum);
              }
              sum-=nums[i];
              i++;
            }
            j++;
        }
      }
        if(mini==INT_MAX)
         return -1;
        else
         return mini;
    }
};