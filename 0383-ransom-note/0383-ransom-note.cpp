class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       int n=ransomNote.length();
       int m=magazine.length();
       unordered_map<char,int>mp;
       if(m<n)
         return false;
       for(int i=0;i<m;i++){
        mp[magazine[i]]++;
       }
       int check=1;
       for(int i=0;i<n;i++){
        int x= ransomNote[i];
        if(mp.find(x)==mp.end()){
            check =0;
            break;
        }else if(mp[ransomNote[i]]>0){
            mp[ransomNote[i]]--;
        }else{
            check=0;
            break;
        }
       }
       if(check==1)
        return true;
       else
        return false; 
    }
};