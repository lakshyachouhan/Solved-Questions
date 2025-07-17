class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int> &nums,int i,int target,int sum){

        if(sum == target)
            return 0 ;

        if(sum > target || i >= nums.size())
            return -1e9 ;

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int incl = 1 + solve(nums,i+1,target,sum+nums[i]);
        int excl = solve(nums,i+1,target,sum);

        return dp[i][sum] = max(incl,excl);
    }


    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        // // dp[i][s]
        // // length of subs. ending at index i with sum as s
        // int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,0));

        // for(int i=0; i<n; i++){

        //     for(int j=0; )
        // }.

        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,target,0);
        return max(ans,-1) ;
    }
};