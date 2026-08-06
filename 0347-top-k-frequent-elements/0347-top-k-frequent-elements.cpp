class Solution {
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
         if(a.first==b.first)
             return a.second>b.second;
          return a.first>b.first;   
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        unordered_map<int,int>frq;
        for(int i=0;i<nums.size();i++){
            frq[nums[i]]++;
        }

        for(auto pairs:frq){
        int el=pairs.first;
        int freq=pairs.second;

        pair<int,int>curr={freq,el};
        if(pq.size()<k){
            pq.push(curr);
            continue;
        }
        if(curr.first<pq.top().first){
            continue;
        }
        pq.pop();
        pq.push(curr);
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};