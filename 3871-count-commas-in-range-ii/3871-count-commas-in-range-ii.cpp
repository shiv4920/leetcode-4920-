class Solution {
public:
    long long countCommas(long long n) {
        long long lower=1000;
        long long  count=0;
        while(lower<=n){
            count+=n-lower+1;
            lower=lower*1000;
        }
        return count;
    }
};