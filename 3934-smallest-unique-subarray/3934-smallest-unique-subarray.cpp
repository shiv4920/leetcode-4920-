
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
        }

        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        rank[sa[0]] = 0;

        for (int i = 1; i < n; i++) {
            rank[sa[i]] = rank[sa[i - 1]];

            if (nums[sa[i]] != nums[sa[i - 1]]) {
                rank[sa[i]]++;
            }
        }

        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + len < n) ? rank[a + len] : -1;
                int y = (b + len < n) ? rank[b + len] : -1;

                return x < y;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = rank[a];
                int b1 = rank[b];

                int a2 = (a + len < n) ? rank[a + len] : -1;
                int b2 = (b + len < n) ? rank[b + len] : -1;

                temp[b] = temp[a];

                if (a1 != b1 || a2 != b2) {
                    temp[b]++;
                }
            }

            rank = temp;
        }

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0) h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int left = lcp[i];
            int right = (i + 1 < n) ? lcp[i + 1] : 0;

            int longestCommon = max(left, right);
            int required = longestCommon + 1;

            if (required <= n - sa[i]) {
                ans = min(ans, required);
            }
        }

        return ans;
    }
};
