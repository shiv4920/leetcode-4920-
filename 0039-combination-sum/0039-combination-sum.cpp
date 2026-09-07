class Solution {
public:
    void fun(int i,int n,int sum,int target,vector<int>&candidates,vector<int>&diary,vector<vector<int>>&res){
     if(i==n){
        if(sum==target)
          res.push_back(diary);
          return;
     }
     //choice 1
     fun(i+1,n,sum,target,candidates,diary,res);
     if(candidates[i]+sum<=target){
        diary.push_back(candidates[i]);
        sum+=candidates[i];
        fun(i,n,sum,target,candidates,diary,res);
        diary.pop_back();
        sum-=candidates[i];
     }

     return ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>diary;
        vector<vector<int>>res;
        fun(0,n,0,target,candidates,diary,res);
        return res;
    }
};