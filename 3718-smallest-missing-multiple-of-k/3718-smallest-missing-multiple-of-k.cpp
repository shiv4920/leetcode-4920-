class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int x=k;

        while(true){
            bool check=false;
          for(int num:nums){
            if(num==x){
                check=true;
                break;
            }
          }
          if(!check)
           return x;
          x+=k;
        }
    }
};