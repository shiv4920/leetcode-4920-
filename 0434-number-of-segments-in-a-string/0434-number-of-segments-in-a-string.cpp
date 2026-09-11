class Solution {
public:
    int countSegments(string s) {
        int n=s.length();
        int c=0;
        int i=0;
        while(i<n){
            if(s[i]!=' '&&(i==0||s[i-1]==' ')){
                c++;
            }
            i++;
        }
        return c;
    }
};