class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>shiv;
        int i=0,j=0;

        while(j<n){
            while(!shiv.empty()&&shiv.back()<nums[j]){
                shiv.pop_back();
            }
            shiv.push_back(nums[j]);
            if(j-i+1==k){
                ans.push_back(shiv.front());
                if(shiv.front()==nums[i]){
                    shiv.pop_front();
                }
                i++;
            }
            j++;
        }
      return ans;
    }
};