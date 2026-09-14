class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long ans=0;
        for(int val:nums){
            ans=ans^val;
        }
        // mask->right most set bit search
        int mask=ans&(-ans);
        int gp1=0;
        int gp2=0;
        for(int num:nums){
            if(num&mask){
                gp1^=num;
            }else{
                gp2^=num;
            }
        }
        return {gp1,gp2}; 
    }
};