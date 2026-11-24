class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        int maxi=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto x:mp){
            if(x.first==x.second){
                maxi=max(maxi,x.second);
            }
        }
        return maxi;
    }
};