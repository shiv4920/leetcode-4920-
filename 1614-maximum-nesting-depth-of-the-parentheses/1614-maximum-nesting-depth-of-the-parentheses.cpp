class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        stack<char>st;
        int count=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                count++;
                maxi=max(maxi,count);
            }else if((!st.empty()&&s[i]==')'&&st.top()=='(')){
                st.pop();
                count--;
            }
        }
        return maxi;
    }
};