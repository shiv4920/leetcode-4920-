class Solution {
     struct cmp{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
         if(a.first==b.first)
             return a.second<b.second;
          return a.first>b.first;   
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        unordered_map<string,int>frq;
        for(int i=0;i<words.size();i++){
            frq[words[i]]++;
        }
        for(auto pairs:frq){
        string el=pairs.first;
        int freq=pairs.second;

        pair<int,string>curr={freq,el};
        if(pq.size()<k){
            pq.push(curr);
            continue;
        }
        if (curr.first > pq.top().first ||
               (curr.first == pq.top().first && curr.second < pq.top().second)) {
                pq.pop();
                pq.push(curr);
               }
        }
         vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};