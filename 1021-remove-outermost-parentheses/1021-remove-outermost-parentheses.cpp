class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        stack<char>st;
        string res="";
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(open>=1){
                    res.push_back(s[i]);
                }
                st.push(s[i]);
                open++;
            }
            if(!st.empty()&&s[i]==')'){
                st.pop();
                open--;
                if(open>=1){
                    res.push_back(s[i]);
                }
            }
        }
        return res;
    }
};