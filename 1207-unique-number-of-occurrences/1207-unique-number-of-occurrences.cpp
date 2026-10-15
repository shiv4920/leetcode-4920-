class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for(auto pair:mp){
            if(st.find(pair.second)!=st.end()){
              return false;
            }
            st.insert(pair.second);  
        }
        return true;
    }
};