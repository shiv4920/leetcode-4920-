class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>win;
        unordered_map<int,int>loss;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            win[matches[i][0]]++;
        }
        for(int i=0;i<n;i++){
            loss[matches[i][1]]++;
        }
        vector<int>res;
        vector<int>res1;
       for(auto pair:win){
        if(loss.find(pair.first)==loss.end())
            res.push_back(pair.first);
       }
       for(auto pair:loss){
        if(pair.second==1)
          res1.push_back(pair.first);
       }

       sort(res.begin(),res.end());
       sort(res1.begin(),res1.end());
        ans.push_back(res);
        ans.push_back(res1);
        return ans;
    }
};