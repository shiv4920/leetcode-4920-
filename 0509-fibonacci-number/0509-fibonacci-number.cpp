class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;

        int a1 = fib(n-1);
        int a2 = fib(n-2);

        return a1+a2;
    }
};