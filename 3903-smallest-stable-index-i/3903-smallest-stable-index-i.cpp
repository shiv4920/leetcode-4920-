class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>pre_max(n);
        vector<int>suff_min(n);
          int maxima= INT_MIN;
        for(int i=0;i<n;i++){
            maxima=max(maxima,nums[i]);
            pre_max[i]=maxima;
        }
        int minima=INT_MAX;
        for(int i=n-1;i>=0;i--){
           minima=min(minima,nums[i]);
           suff_min[i]=minima;
        }

       int i=0;
       int minima2=0;
       int score=0;
       while(i<n){
        int minima1=-1;
        score=pre_max[i]-suff_min[i];
          if(score<=k)
            return i;
        i++;
       } 

        return -1;  
    }
};