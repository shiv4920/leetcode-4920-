class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums2.size();
        vector<int>diffCount(1e5+1,0);
        for(int i=0;i<n;i++){
          int d=abs(nums1[i]-nums2[i]);
          diffCount[d]++;
        }
        int k=k1+k2;
        for(int i=1e5;i>0&&k>0;i--){
           int Countops=min(diffCount[i],k);
           diffCount[i]-=Countops;
           diffCount[i-1]+=Countops;
           k-=Countops;
        }
        long long res=0;
        for(long long i=1;i<=1e5;i++){
            res+=(diffCount[i]*i*i);
        }
        return res;
    }
};