class Solution {
public:
    int firstUniqChar(string s) {
           int n=s.length();
           bool found=false;
           unordered_map<char,int>f;
           for(int i=0;i<n;i++){
            f[s[i]]++;
           }
           for(int i=0;i<n;i++){
            if(f[s[i]]==1){
                return i;
                found=true;
                break;
            }
           }
           if(!found)
            return -1;
        return -1;
    }
};