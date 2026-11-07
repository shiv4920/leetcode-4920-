
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                available.push({w, idx});
            }

            if(available.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) == time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    available.push({w, idx});
                }
            }

            auto [w, idx] = available.top();
            available.pop();

            ans[j] = idx;

            busy.push({time + tasks[j], w, idx});
        }

        return ans;
    }
};
