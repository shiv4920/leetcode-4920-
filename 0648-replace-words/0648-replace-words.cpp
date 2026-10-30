class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=dictionary.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[dictionary[i]]=1;
        }
        stringstream ss(sentence);
        string word="";
        string res="";
        while(ss>>word){
            string ans=word;
            for(int i=0;i<word.length();i++){
             string temp=word.substr(0,i);
             if(mp.find(temp)!=mp.end()){
               ans=temp;
               break;
             }
            }

          if(!res.empty()){
            res+=" "; 
          }
          res+=ans;
        }
     return res;
    }
};