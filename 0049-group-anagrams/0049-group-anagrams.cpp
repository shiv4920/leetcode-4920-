class Solution {
public:
    string fun(string x){
        sort(x.begin(),x.end());
        return x;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
       unordered_map<string,vector<string>>mp;
       
       for(int i=0;i<n;i++){
        mp[fun(strs[i])].push_back(strs[i]);
       }
       vector<vector<string>>nums;
       for(auto x:mp){
        nums.push_back(x.second);
       }
     return nums; 
    }
};