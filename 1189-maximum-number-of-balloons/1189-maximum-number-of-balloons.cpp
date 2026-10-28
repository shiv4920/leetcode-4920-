class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='b'||s[i]=='a'||s[i]=='l'||s[i]=='o'||s[i]=='n'){
                mp[s[i]]++;
            }
        }
        mp['l']=mp['l']/2;
        mp['o']=mp['o']/2;
        if(mp.size()!=5)
           return 0;
        int mini=INT_MAX;
        for(auto x:mp){
         mini=min(mini,x.second);
        }
        return mini;
    }
};