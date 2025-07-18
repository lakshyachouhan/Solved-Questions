class Solution {
public:
    vector<vector<int>> dp ;
    int solve(vector<int>& nums,int i,int last){

        if(i >= nums.size()){

            if(last < nums.size())
                return nums[last];

            return 0 ;
        }

        if(dp[i][last] != -1)
            return dp[i][last] ;

        int op1 = max(nums[i],nums[last]) + solve(nums,i+2,i+1);

        int op2  = 1e9 , op3 = 1e9;
        if(i+1 < nums.size())
             op2 = max(nums[i+1],nums[last]) + solve(nums,i+2,i);

        
        if(i+1 < nums.size())
             op3 = max(nums[i],nums[i+1]) + solve(nums,i+2,last);

        return dp[i][last] = min({op1,op2,op3});
    }


    int minCost(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];

        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        int ans = solve(nums,1,0);
        return ans ;
    }
};