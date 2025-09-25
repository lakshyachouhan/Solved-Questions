class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& triangle,int i,int j){

        if(i >= triangle.size()){
            return 0;
        }

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        int curr = triangle[i][j];
        int op1 = solve(triangle,i+1,j);
        int op2  = solve(triangle,i+1,j+1);

        return dp[i][j] =  curr + min(op1,op2);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        
        // memset(dp,INT_MAX,sizeof(dp));
        fill(&dp[0][0], &dp[0][0] + 201*201, INT_MAX);
        int ans = solve(triangle,0,0);
        return ans ;
    }
};