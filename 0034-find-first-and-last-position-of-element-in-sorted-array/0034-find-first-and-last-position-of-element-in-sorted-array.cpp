class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int i=0;
      int j=nums.size()-1;
      int first=-1;
      while(i<=j){
        int low=(i+j)/2;
        if(nums[low]<target){
          i=low+1;
        }
        else if(nums[low]>target){
           j=low-1;
        }
        else{
           first=low;
            j=low-1;
        }       
      } 

      i=0;
      j=nums.size()-1;
      int last=-1;
       while(i<=j){
        int low=(i+j)/2;
        if(nums[low]<target)
          i=low+1;
        else if(nums[low]>target)
           j=low-1;
        else{
           last=low;
           i=low+1;
        }     
      } 
      return {first,last};
    }
};