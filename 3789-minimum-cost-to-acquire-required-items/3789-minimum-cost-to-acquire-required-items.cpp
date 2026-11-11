class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common=min(need1,need2);
        long long rem1=need1-common;
        long long rem2=need2-common;
        long long ans1=common*costBoth+rem1*min(cost1,costBoth)+rem2*min(cost2,costBoth);
        long long ans2=1LL*max(need1,need2)*costBoth;
        long long ans3=1LL*need1*cost1+1LL*need2*cost2;
        return min({ans1,ans2,ans3});
    }
};