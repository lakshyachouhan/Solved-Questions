class Solution {
public:

    int dp[71][71][71];
    int solve(vector<vector<int>>& grid,int c1,int c2,int row){

        if(row >= grid.size())
            return 0 ;

        if(dp[c1][c2][row] != -1)
            return dp[c1][c2][row];

        int dy[] = {-1,0,1};

        int val = 0 ,ans = 0 ;
        if(c1 == c2)    val = grid[row][c1];
        else val = grid[row][c1] + grid[row][c2];

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){

                int newC1 = c1 + dy[i] ;
                int newC2 = c2 + dy[j] ;

                if(newC1>=0 && newC2>=0 && newC1 < grid[0].size() && newC2 < grid[0].size()){
                    int curr = val + solve(grid,newC1,newC2,row+1); 
                    ans = max(ans,curr);
                }                
            }
        }

        return dp[c1][c2][row] =  ans ;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        int col = grid[0].size() ;
        int ans = solve(grid,0,col-1,0);
        return ans ;
    }
};