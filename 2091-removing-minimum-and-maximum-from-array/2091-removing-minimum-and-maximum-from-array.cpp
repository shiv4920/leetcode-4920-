class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
         
         int maxima=INT_MIN;
         int minima=INT_MAX;
         

         int maxima1=0;
         int minima1=0;

         if(n==1)
            return 1;

         for(int i=0;i<n;i++){
            
            if(nums[i]>maxima){
                maxima=nums[i];
                maxima1=i;
            }
            if(nums[i]<minima){
                minima=nums[i];
                minima1=i;
            }
         }
       
       int front=max(maxima1,minima1)+1;
       int back=max(n-maxima1,n-minima1);
       int both=min((maxima1+1)+(n-minima1),(minima1+1)+(n-maxima1));
       return min(front,min(back,both));
    }
};