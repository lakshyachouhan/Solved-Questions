class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) dp[0][0][1] = 0;  
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == INT_MIN) continue;
                    
                    if (j + 1 < n) {

                        dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] + coins[i][j+1]);

                        if (k < 2 && coins[i][j+1] < 0) {
                            dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k]);
                        }
                    }
                    
                    if (i + 1 < m) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + coins[i+1][j]);
                        
                        if (k < 2 && coins[i+1][j] < 0) {
                            dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
                        }
                    }
                }
            }
        }
        

        int ans = INT_MIN;
        for (int k = 0; k < 3; k++) {
            ans = max(ans, dp[m-1][n-1][k]);
        }
        return ans;
    }
};