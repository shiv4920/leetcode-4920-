class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int>freq;
        unordered_map<char,int>free;
        for(int i=0;i<m;i++){
            freq[tasks[i]]++;
            free[tasks[i]]=1;
        }
        

        priority_queue<pair<int,char>>pq;
        for(auto ans:freq){
            pq.push({ans.second,ans.first});
        }
        int seat=1;
        while(!pq.empty()){
            vector<pair<int,char>>pull;
            while(!pq.empty()){
                pair<int,char>p=pq.top();
                 pq.pop();
                int fr=p.first;
                int child=p.second;
                if(free[child]<=seat){
                    if(p.first>1)
                     pq.push({p.first-1,p.second});
                     free[p.second]=seat+n+1;
                     break;
                }else{
                    pull.push_back(p);
                }
            }
            for(int i=0;i<pull.size();i++)
              pq.push(pull[i]);
            seat++;
        }
        return seat-1;
    }
};