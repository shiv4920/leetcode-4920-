class Solution {
public:
    bool fun(string&s,int low,int high){
        int len=high-low+1;
        if(len==0||len==1) return true;
        if(s[low]!=s[high]) return false;

        return fun(s,low+1,high-1);
        }
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.length();
        int low = 0;
        int high = n-1;
        return fun(s,low,high);
        
    }
};