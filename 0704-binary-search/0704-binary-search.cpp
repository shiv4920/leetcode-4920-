class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int p=(i+j)/2;
            if(nums[p]==target)
             return p;
            else if(nums[p]<target)
              i=p+1;
            else
               j=p-1;
        } 
        return -1;
    }
};