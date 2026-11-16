
class Solution {
public:
    string Digit(string x) {
        int sum = 0;

        for (char c : x) {
            sum += c - '0';
        }

        return to_string(sum);
    }

    string digitSum(string s, int k) {
        while (s.length() > k) {
            string ans = "";

            for (int i = 0; i < s.length(); i += k) {
                string str = s.substr(i, k);
                ans += Digit(str);
            }

            s = ans;
        }

        return s;
    }
};
