class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int minx=*min_element(begin(nums1),end(nums1));

        if(minx%2==1){
            return true;
        }

        for(int x:nums1){
            if(x%2==1)
            return false;
        }

    return true;
    }
};