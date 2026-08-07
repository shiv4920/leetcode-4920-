class Solution {
public:
     int distance(vector<vector<int>>&points,int i){
        return points[i][0]*points[i][0]+points[i][1]*points[i][1];
     }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<k;i++){
            int dis=distance(points,i);
            pq.push({dis,i});
        }
        for(int i=k;i<points.size();i++){
            int dis=distance(points,i);
         if(dis>=pq.top().first){
            continue;
         }
         pq.pop();
         pq.push({dis,i});
        }
        vector<vector<int>>res;
        while(!pq.empty()){
           res.push_back(points[pq.top().second]);
           pq.pop();
        }
        return res;
    }
};