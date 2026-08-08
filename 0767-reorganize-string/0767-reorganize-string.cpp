class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ans += curr.second;
            curr.first--;
            if(prev.first > 0) {
                pq.push(prev);
            }
            prev = curr;
        }

        if(prev.first > 0) {
            return "";
        }

        return ans;
    }
};