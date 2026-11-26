class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]>1){
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                   if(mp[s[i]]==0){
                      mp.erase(s[i]);
                   }
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};