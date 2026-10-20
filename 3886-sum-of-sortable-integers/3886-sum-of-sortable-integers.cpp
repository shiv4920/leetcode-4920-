class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Find all divisors of n
        std::vector<int> divisors;
        for (int i = 1; i <= std::sqrt(n); ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        long long total_sum = 0;
        
        for (int k : divisors) {
            bool is_valid = true;
            
            // 1. Check if every block can be cyclically rotated into sorted order
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (curr > next) {
                        drops++;
                    }
                }
                if (drops > 1) {
                    is_valid = false;
                    break;
                }
            }
            
            if (!is_valid) continue;
            
            // 2. Check if the maximum of each block is <= the minimum of the next block
            // To do this efficiently, we can find the min/max of each block.
            int prev_max = -1e9;
            for (int i = 0; i < n; i += k) {
                int block_min = 1e9, block_max = -1e9;
                for (int j = 0; j < k; ++j) {
                    block_min = std::min(block_min, nums[i + j]);
                    block_max = std::max(block_max, nums[i + j]);
                }
                
                if (prev_max > block_min) {
                    is_valid = false;
                    break;
                }
                prev_max = block_max;
            }
            
            if (is_valid) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};