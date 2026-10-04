class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        stack<char>open;
        stack<char>star;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
              open.push(i);
            if(s[i]=='*')
              star.push(i);
            if(!open.empty()&&s[i]==')')
               open.pop();
            else if(!star.empty()&&s[i]==')')
               star.pop();
            else if(star.empty()&&s[i]==')')
               return false;
        }
        while(!open.empty()&&!star.empty()){
            if(open.top()<star.top()){
                 open.pop();
                 star.pop();
            }else{
                return false;
            }
        }  
        if(open.empty())
          return true;
        else
          return false;  
    }
};