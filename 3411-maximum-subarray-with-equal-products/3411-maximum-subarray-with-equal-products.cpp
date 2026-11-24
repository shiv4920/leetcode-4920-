class Solution {
public:
    vector<int> getFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            factors[i] = getFactors(nums[i]);
        }

        unordered_set<int> used;

        int left = 0;
        int ans = 2;

        for (int right = 0; right < n; right++) {

            bool conflict = false;

            while (true) {
                conflict = false;

                for (int p : factors[right]) {
                    if (used.count(p)) {
                        conflict = true;
                        break;
                    }
                }

                if (!conflict) break;

                for (int p : factors[left]) {
                    used.erase(p);
                }

                left++;
            }

            for (int p : factors[right]) {
                used.insert(p);
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};