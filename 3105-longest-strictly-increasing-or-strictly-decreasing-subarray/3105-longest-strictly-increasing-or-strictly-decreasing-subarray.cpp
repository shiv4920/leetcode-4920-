
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int m1 = 1, m2 = 1;
        int cnt1 = 1, cnt2 = 1;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] < nums[i+1]) {
                cnt1++;
            }
            else {
                m1 = max(m1, cnt1);
                cnt1 = 1;
            }
        }
        m1 = max(m1, cnt1);

        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                cnt2++;
            }
            else {
                m2 = max(m2, cnt2);
                cnt2 = 1;
            }
        }
        m2 = max(m2, cnt2);

        return max(m1, m2);
    }
};
