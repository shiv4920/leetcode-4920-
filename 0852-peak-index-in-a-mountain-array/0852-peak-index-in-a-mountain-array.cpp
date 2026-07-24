class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int j=arr.size();
        int ans=-1;
        while(i<=j){
            int low=(i+j)/2;
            if(arr[low]>arr[low+1]){
                ans=low;
                j=low-1;
            }else{
                i=low+1;
            }
        }
        return ans;
    }
};