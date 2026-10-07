class Solution {
    set<string> ans;

    bool valid(string s) {
        int count = 0;

        for(char ch : s) {
            if(ch == '(')
                count++;

            else if(ch == ')') {
                count--;

                if(count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    void backtrack(string s, int start, int remove) {

        if(remove == 0) {
            if(valid(s))
                ans.insert(s);

            return;
        }

        for(int i = start; i < s.length(); i++) {

            if(s[i] != '(' && s[i] != ')')
                continue;

            // Avoid removing same consecutive parenthesis
            if(i > start && s[i] == s[i-1])
                continue;

            string temp = s.substr(0, i) + s.substr(i + 1);

            backtrack(temp, i, remove - 1);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        int remove = 0;
        int count = 0;

        // Find minimum number of removals
        for(char ch : s) {

            if(ch == '(') {
                count++;
            }
            else if(ch == ')') {

                if(count > 0)
                    count--;
                else
                    remove++;
            }
        }

        remove += count;

        backtrack(s, 0, remove);

        return vector<string>(ans.begin(), ans.end());
    }
};