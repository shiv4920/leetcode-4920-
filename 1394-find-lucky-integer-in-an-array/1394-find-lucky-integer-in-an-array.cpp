class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        bool check=false;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto pair:mp){
            if(pair.first==pair.second){
                check=true;
                maxi=max(maxi,pair.first);
            }
        }
        if(!check)
          return -1;
        else
          return maxi; 

    }
};