class Solution {
public:
    vector<vector<int>> dp ;
    int solve(int n,int prevCopy ,int curr){

        if(curr > n )
            return 1e9 ;

        if(curr == n)   return 0 ;

        if(dp[prevCopy][curr] != -1)
            return dp[prevCopy][curr];

        int pasteAll = 1e9 , copyAll = 1e9;
        if(prevCopy != 0)
             pasteAll = 1 + solve(n,prevCopy,curr+prevCopy);

        if(prevCopy != curr)
             copyAll = 1 + solve(n,curr,curr);

        return dp[prevCopy][curr] = min(copyAll,pasteAll);
    }

    int minSteps(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = solve(n,0,1);
        return ans ;
    }
};