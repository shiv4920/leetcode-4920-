class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        bool found=false;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==1){
             found = true;
              return i;
              break;
            }
        }
        if(!found)
          return -1;
        return -1;
    }
};