class Solution {
public:
    using ll = long long;

    multiset<ll> low, high;
    ll sumLow = 0, sumHigh = 0;

    void add(ll val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }
        balance();
    }

    void remove(ll val) {
        auto it = low.find(val);

        if (it != low.end()) {
            sumLow -= val;
            low.erase(it);
        } else {
            it = high.find(val);
            sumHigh -= val;
            high.erase(it);
        }

        balance();
    }

    void balance() {
        int need = (low.size() + high.size() + 1) / 2;

        while (low.size() > need) {
            auto it = prev(low.end());
            ll val = *it;

            sumLow -= val;
            low.erase(it);

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < need) {
            auto it = high.begin();
            ll val = *it;

            sumHigh -= val;
            high.erase(it);

            low.insert(val);
            sumLow += val;
        }
    }

    ll getCost() {
        ll median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<ll> cost(n - x + 1);

        low.clear();
        high.clear();
        sumLow = sumHigh = 0;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(k + 1,
                              vector<ll>(n + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};