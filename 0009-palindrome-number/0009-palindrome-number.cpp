class Solution {
public:
    bool isPalindrome(int x) {
        string ans=to_string(x);
        int i=0,j=ans.length()-1;
        
        while(i<j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};