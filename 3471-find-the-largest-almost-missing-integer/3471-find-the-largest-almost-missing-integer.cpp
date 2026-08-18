class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
       if(k==1){

        unordered_map<int,int>mp;
        for(int val:nums){
            mp[val]++;
        }
        int ans=-1;
        for(auto pair:mp){
            if(pair.second==1){
                ans=max(ans,pair.first);
            }
        }
        return ans;
       }
        int ans=0;
       if(k==n){
        for(int val:nums){
            ans=max(ans,val);
        }
        return ans;
       }

       int first=nums[0];
       int last= nums[n-1];
        int firstcount=0;
        int lastcount=0;
        for(int val:nums){
            if(val==first){
                firstcount++;
            }
            if(val==last){
                lastcount++;
            }
        }

        if(firstcount==1&&lastcount==1){
            return max(first,last);
        }
        if(firstcount==1)
         return first;

        if(lastcount==1)
         return last; 
   
      return -1;

    }
};