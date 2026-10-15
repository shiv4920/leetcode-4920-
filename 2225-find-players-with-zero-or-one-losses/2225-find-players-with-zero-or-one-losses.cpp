class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>loss;
        for(int i=0;i<n;i++){
            int loser=matches[i][1];
            loss[loser]++;
        }
        
        vector<int>notloss;
        vector<int>oneloss;

        for(int i=0;i<n;i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            if(loss.find(winner)==loss.end()){
               notloss.push_back(winner);
               loss[winner]=2;
            } 
            if(loss[loser]==1){
              oneloss.push_back(loser);
            }   
        }
         
        sort(notloss.begin(),notloss.end());
        sort(oneloss.begin(),oneloss.end());
        vector<vector<int>>ans;
        ans.push_back(notloss);
        ans.push_back(oneloss);
        


        return ans;
    }
};