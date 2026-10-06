class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        stack<char>opend;
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
              opend.push(s[i]);
              open++;
            }
            if(!opend.empty()&&s[i]==')'){
                opend.pop();
                open--;
            }else if(opend.empty()&&s[i]==')'){
                close++;
            }    
        }
        while(!opend.empty()){
            opend.pop();
        }
        return (open+close);
    }
};