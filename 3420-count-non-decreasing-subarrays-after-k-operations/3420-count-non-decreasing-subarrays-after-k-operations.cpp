
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 18;

        vector<int> nxt(n + 1, n);
        vector<int> st;

        // Next greater element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                nxt[i] = st.back();
            }

            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        // Binary lifting initialization
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];

                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Calculate operations required for [l, r]
        auto cost = [&](int l, int r) -> long long {
            long long total = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                int next = up[j][cur];

                if (next <= r + 1) {
                    total += sum[j][cur];
                    cur = next;
                }
            }

            if (cur <= r) {
                total += 1LL * nums[cur] * (r - cur + 1);
            }

            long long original = pref[r + 1] - pref[l];

            return total - original;
        };

        // Sliding window
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            while (left <= right && cost(left, right) > k) {
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
