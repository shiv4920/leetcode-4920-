class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
         
        if(is_sorted(begin(s),end(s)))
           return 0;

        if(n==2)
         return -1;
        char min_char=*min_element(begin(s),end(s));
        char max_char=*max_element(begin(s),end(s));
        
        if(s[0]==min_char||s[n-1]==max_char)
         return 1;

        char mid_min=*min_element(begin(s)+1,end(s)-1);
        char mid_max=*max_element(begin(s)+1,end(s)-1);

        if(s[0]>mid_max && s[n-1]<mid_min)
         return 3;
        else
         return 2;  
    }
};