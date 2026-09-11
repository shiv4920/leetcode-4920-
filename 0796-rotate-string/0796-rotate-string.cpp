class Solution {
public:
    bool rotateString(string s, string goal) {
     //for(int i=0;i<n;i++){
       // rotate(begin(s),begin(s)+1,end(s));
        //if(s==goal) return true;
     //}  
     //return false;
     if(s.length()!=goal.length()){
        return false;
     }

      if((s+s).find(goal)!=string::npos){
         return true; 
      }
        return false;
    }
};