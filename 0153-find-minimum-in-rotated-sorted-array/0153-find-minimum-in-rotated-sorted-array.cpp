class Solution {
public:
    int findMin(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int ans=-1;
        while(i<=j){
            int low =(i+j)/2;
            if(arr[low]>arr[arr.size()-1]){
                i=low+1;
            }else{
                ans=low;
                j=low-1;
            }
        }
        return {arr[ans]};
    }
};