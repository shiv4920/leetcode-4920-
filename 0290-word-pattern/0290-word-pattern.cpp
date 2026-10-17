class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>ans;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                res.push_back(s[i]);
            }else{
                ans.push_back(res);
                res="";
            }
        }
        ans.push_back(res);
        if(pattern.length()!=ans.size())
             return false;
        unordered_map<char,string>mp;
        unordered_map<string,char>mp1;
        for(int i=0;i<ans.size();i++){
            char ch=pattern[i];
            string word=ans[i];
            if(mp.find(ch)!=mp.end()&&mp[ch]!=word)
                return false;
            if(mp1.find(word)!=mp1.end()&&mp1[word]!=ch)
                return false;
            mp[ch]=word;
            mp1[word]=ch;        
        }
    return true;
    }
};