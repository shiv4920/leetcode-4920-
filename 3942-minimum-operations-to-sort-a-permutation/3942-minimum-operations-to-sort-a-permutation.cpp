#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        
        // Find the index of 0
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        
        int min_ops = INT_MAX;
        
        // Helper lambda to check if elements follow a step pattern (+1 or -1)
        auto check = [&](int step) {
            for (int i = 1; i < n; ++i) {
                int prev = (zero + (i - 1) * step) % n;
                if (prev < 0) prev += n;
                
                int curr = (zero + i * step) % n;
                if (curr < 0) curr += n;
                
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };
        
        // Case with step = +1 (Increasing to the right)
        if (check(1)) {
            // Option A: Pure rotation (zero operations)
            min_ops = std::min(min_ops, zero);
            // Option B: Rotate, Reverse, then Rotate back (n - zero + 2 operations)
            min_ops = std::min(min_ops, n - zero + 2);
        }
        
        // Case with step = -1 (Increasing to the left / reverse direction)
        if (check(-1)) {
            // Option C: Rotate then Reverse (zero + 2 operations)
            min_ops = std::min(min_ops, zero + 2);
            // Option D: Reverse then Rotate (n - zero operations)
            min_ops = std::min(min_ops, n - zero);
        }
        
        return (min_ops == INT_MAX) ? -1 : min_ops;
    }
};