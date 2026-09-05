class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffix(n);
        int min_suff=INT_MAX;
        for(int i=n-1;i>=0;i--){
        min_suff=min(min_suff,nums[i]);
        suffix[i]=min_suff;
        }

        int prefix=0;
        for(int i=0;i<n;i++){
        prefix=max(prefix,nums[i]);
        int score=prefix-suffix[i];
          if(score<=k)
             return i;
        }
        return -1;
    }
};