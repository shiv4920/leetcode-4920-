

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int ans = -1; // -1 represents all bits set (0xFFFFFFFF)
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }
        
        return ans == -1 ? 0 : ans;
    }
};