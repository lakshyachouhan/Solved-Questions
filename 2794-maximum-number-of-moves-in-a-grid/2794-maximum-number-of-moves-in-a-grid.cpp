class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& grid,int i,int j){

        int m = grid.size();
        int n = grid[0].size();

        if(dp[i][j] != -1)
            return dp[i][j];

        int op1 = 0 , op2 = 0 , op3 = 0 ;
        if(i+1<m && j+1 < n && grid[i+1][j+1] > grid[i][j])     op1 = 1 + solve(grid,i+1,j+1);
        if(i<m && j+1 < n && grid[i][j+1] > grid[i][j])       op2 = 1 + solve(grid,i,j+1);
        if(i-1>=0 && j+1 < n && grid[i-1][j+1] > grid[i][j])    op3 = 1 + solve(grid,i-1,j+1);

        return dp[i][j] = max({op1,op2,op3});
    }



    int maxMoves(vector<vector<int>>& grid) {
        
        int ans = -1 ;
        int m = grid.size();
        int n = grid[0].size();

        memset(dp,-1,sizeof(dp));
        for(int i=0; i<m; i++){

            int curr = solve(grid,i,0);
            ans = max(ans,curr);
        }

        return ans ;
    }
};