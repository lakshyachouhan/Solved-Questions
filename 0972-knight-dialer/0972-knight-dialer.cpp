class Solution {
public:

    unordered_map<int,vector<int>> moves = {{1,{6,8}},{2,{7,9}},{3,{4,8}},{4,{0,3,9}},{6,{0,1,7}},{7,{2,6}},{8,{1,3}},{9,{2,4}},{0,{4,6}}};
    int MOD = 1e9 + 7 ;

    int dp[5002][10] ;

    int allWays(int n,int currNo){

        if(n == 0)
            return 1 ;

        if(dp[n][currNo] != -1)
            return dp[n][currNo];

        int ways = 0 ;
        for(auto nbr:moves[currNo]){
            ways = (ways + allWays(n-1,nbr)%MOD)%MOD;
        }

        return dp[n][currNo] = ways ;
    }

    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
        int ans = 0 ;
        for(int i=0; i<=9; i++){
            int curr = allWays(n-1,i);
            ans = (ans + curr%MOD)%MOD ;
        }

        return ans ;
    }
};