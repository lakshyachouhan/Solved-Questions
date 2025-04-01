#define ll long long 

class Solution {
public:
    ll dp[100001];

    ll solve(vector<vector<int>>& questions,int i){

        if(i >= questions.size())
            return 0 ;

        if(dp[i] != -1)
            return dp[i];

        int p = questions[i][0] , skip = questions[i][1];

        ll include = p + solve(questions,i+skip+1);
        ll exclude = 0 + solve(questions,i+1);

        return dp[i] = max(include,exclude);
    }



    long long mostPoints(vector<vector<int>>& questions) {
        
        memset(dp,-1,sizeof(dp));
        ll ans = solve(questions,0);
        return ans ;
    }
};