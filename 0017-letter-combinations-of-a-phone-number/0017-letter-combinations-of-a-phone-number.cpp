class Solution {
public:
    unordered_map<char,string>mp={
     {'2',"abc"},
     {'3',"def"},
     {'4',"ghi"},
     {'5',"jkl"},
     {'6',"mno"},
     {'7',"pqrs"},
     {'8',"tuv"},
     {'9',"wxyz"},
    };
    void fun(string& digits,int n,int i,string& diary,vector<string>& res){
        if(i==n){
            res.push_back(diary);
            return;
        }
      string choice=mp[digits[i]];
      for(int j=0;j<choice.size();j++){
        diary.push_back(choice[j]);
        fun(digits,n,i+1,diary,res);
        diary.pop_back();
      }
      return ;
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        string diary="";
        vector<string>res;
        fun(digits,n,0,diary,res);
        return res;
    }
};