class Solution {
public:
    void fun(int i,int j,int n,string&temp,vector<string>&res){
        if(i==n&&j==n){
         res.push_back(temp);
            return;
        }
        //open
        if(i<n){
            temp.push_back('(');
            fun(i+1,j,n,temp,res);
            temp.pop_back();
        }

        //close
        if(j<i){
            temp.push_back(')');
            fun(i,j+1,n,temp,res);
            temp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp="";
        fun(0,0,n,temp,res);
        return res;
    }
};