class Solution {
public:
    int longestPalindrome(string s) {
       int n=s.length();
       unordered_map<char,int>mp;
       for(int i=0;i<n;i++){
        mp[s[i]]++;
       }
       int count=0;
       bool odd=false;
      for(auto x:mp){
        int y=x.second;
        if(y%2==0){
            count+=y;
        }else{
            count+=y-1;
            odd=true;
        }

      }
      if(odd){
        count+=1;
      }
      return count;
    }
};