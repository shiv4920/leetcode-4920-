class Solution {
    int Mod=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        

        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0&&(mp.find(arr[i]/arr[j])!=mp.end())){
                mp[arr[i]]=(mp[arr[i]]+mp[arr[j]]*mp[arr[i]/arr[j]])%Mod;
            }
            }
        }
        long long count=0;
        for(auto x:mp){
            count=(count+x.second)%Mod;
        }
        return count;
    }
};