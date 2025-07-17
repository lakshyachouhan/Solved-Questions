class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        // For each index , i will check 
        // max length of the subsequence ending at index i
        // having sum of adj. elements % k as curr
        // dp[i][curr]
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k,1));
        int ans = 0 ;

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){

                int curr = (nums[i]+nums[j])%k ;
                dp[i][curr] = max(dp[i][curr],dp[j][curr]+1);
                ans = max(ans,dp[i][curr]);
            }
        }

        return ans ;
    }
};