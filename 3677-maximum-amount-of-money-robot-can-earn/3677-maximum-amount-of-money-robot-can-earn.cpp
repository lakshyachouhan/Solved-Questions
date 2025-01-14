class Solution {
public:
    // int dp[501][501][3];

    // int solve(vector<vector<int>>& coins,int i,int j,int limit){

    //     if(i >= coins.size() || j >= coins[0].size())
    //         return -1e9;

    //     if(i == coins.size()-1 && j == coins[0].size()-1){

    //         if(limit < 2 && coins[i][j] < 0)
    //             return 0 ;

    //         else return coins[i][j]; 
    //     }

    //     if( dp[i][j][limit] != -1)
    //         return  dp[i][j][limit]  ;

    //     // include matlab limit mein +1
    //     int include = -1e9 ;
    //     if(coins[i][j] < 0 && limit < 2){

    //         int op1 = 0 + solve(coins,i+1,j,limit+1);
    //         int op2 = 0 + solve(coins,i,j+1,limit+1);

    //         include = max(op1,op2);
    //     }

    //     int op3 = coins[i][j] + solve(coins,i+1,j,limit);
    //     int op4 = coins[i][j] + solve(coins,i,j+1,limit);
    //     int exclude = max(op3,op4);

    //     return dp[i][j][limit] = max(include,exclude);        
    // }

    int solveTab(vector<vector<int>>& coins){
        
        int m = coins.size() , n = coins[0].size() ;
        int dp[501][501][3];
        memset(dp,-1e9,sizeof(dp));

        dp[m-1][n-1][2] = coins[m-1][n-1];

        if(coins[m-1][n-1] < 0){
            dp[m-1][n-1][0] = dp[m-1][n-1][1] = 0 ;
        }

        else  dp[m-1][n-1][0] = dp[m-1][n-1][1] = coins[m-1][n-1];

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                for(int limit=2; limit>=0; limit--){

                    if(i == m-1 && j == n-1)
                        continue;

                      int include = -1e9 , exclude = -1e9; ;
                       if(coins[i][j] < 0 && limit < 2){

                             if(j + 1 < n) 
                                include = max(include, dp[i][j+1][limit+1]);
                            
                            if(i + 1 < m) 
                                include = max(include, dp[i+1][j][limit+1]);
                            
                        }

                         if(j + 1 < n) 
                                exclude = max(exclude, coins[i][j] + dp[i][j+1][limit]);
                            
                            if(i + 1 < m) 
                                exclude = max(exclude, coins[i][j] + dp[i+1][j][limit]);
                            

                        dp[i][j][limit] = max(include,exclude);        
                }
            }
        }

        return dp[0][0][0];       

    }

    int maximumAmount(vector<vector<int>>& coins) {
        
        // memset(dp,-1,sizeof(dp));
        // int ans = solve(coins,0,0,0);

        int ans = solveTab(coins);
        return ans ;
    }
};