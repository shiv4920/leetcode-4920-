class Solution {
public:
    

    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<int>Sorted(nums);
        auto lambda =[&](int num1,int num2){
            int dsum1=getDigitSum(num1);
            int dsum2=getDigitSum(num2);
            if(dsum1!=dsum2)
               return dsum1<dsum2;
            return num1<num2;   
        };
        sort(Sorted.begin(),Sorted.end(),lambda);

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
          mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(Sorted[i]==nums[i])
              continue;
            if(Sorted[i]!=nums[i]){
              int idx=mp[Sorted[i]];
              int old=nums[i];
              swap(nums[i],nums[idx]);
              mp[Sorted[i]]=i;
              mp[old]=idx;
              count++;
            }
    
        }
        return count;

    }
};