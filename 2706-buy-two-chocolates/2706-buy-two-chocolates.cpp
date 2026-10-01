class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<mini1){
                mini2=mini1;
                mini1=prices[i];
            }else if(prices[i]<mini2){
                mini2=prices[i];
            }
              
        } 
        int sum=mini1+mini2;
        if(sum<=money)
          return (money-sum);
        else
          return money;  
    }
};