
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.clear();
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
        }
        else {
            if (prefix.empty()) {
                prefix.push_back(num);
            }
            else {
                prefix.push_back(prefix.back() * num);
            }
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        if (k > n) {
            return 0;
        }

        if (k == n) {
            return prefix.back();
        }

        return prefix.back() / prefix[n - k - 1];
    }
};
