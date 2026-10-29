class Solution {
public:
    bool canConstruct(string p, string s) {
        int n=p.length();
        int m=s.length();
        unordered_map<char,int>f;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            f[p[i]]++;
        }
        for(int i=0;i<m;i++){
            mp[s[i]]++;
        }
            for(auto i:f){
                char c=i.first;
                int l=i.second;
                int k=mp[c];
                if(k<l)
                return false;
            }
           return true;
        }
};