class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }
        for(auto count:freq){
            if(count.second>(n+1)/2)
             return "";
        }

        priority_queue<pair<int, char>,vector<pair<int,char>>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(pq.size()>=2) {
            auto curr1 = pq.top();
            pq.pop();
            auto curr2=pq.top();
            pq.pop();
            ans += curr1.second;
            ans+=curr2.second;
            curr1.first--;
            curr2.first--;
            if(curr1.first > 0) {
                pq.push(curr1);
            }
            if(curr2.first>0){
                pq.push(curr2);
            }
        }

        if(!pq.empty()){
            ans+=pq.top().second;
        }

        return ans;
    }
};