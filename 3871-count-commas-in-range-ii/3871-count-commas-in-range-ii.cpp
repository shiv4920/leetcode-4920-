class Solution {
public:
    long long countCommas(long long n) {
        long long lower=1000;
        long long  count=0;
        long long comm=1;
        while(lower<=n){
            long long upper=lower*1000-1;
            if(upper>n){
             upper=n;
            }
            count+=(upper-lower+1)*comm;
            lower=lower*1000;
            comm++;
        }
        return count;
    }
};