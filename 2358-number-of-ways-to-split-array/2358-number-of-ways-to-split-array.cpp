class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int ans = 0 ;
        long long  sum = 0 ;

        long long  total = accumulate(nums.begin(),nums.end(),0*1LL);

        for(int i=0; i<nums.size()-1; i++){

            sum += nums[i] ;
            long long  rightSum = total - sum ;

            if(sum >= rightSum) ans++;
        }

        return ans ;
    }
};