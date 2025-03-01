class Solution {
public:
    int dp[2000][4000];
    int solve(vector<int> &v,int i,int sum){

        if(i >= v.size())
            return sum ;

        if(dp[i][sum] != -1)
            return dp[i][sum];

        int include = 0 ;
        if(sum < v[i])
            include = solve(v,i+1,sum+v[i]);

        int exclude = solve(v,i+1,sum);

        return dp[i][sum] =  max(include,exclude);
    }


    int maxTotalReward(vector<int>& rewardValues) {
        
        memset(dp,-1,sizeof(dp));
        sort(rewardValues.begin(),rewardValues.end());
        int ans = solve(rewardValues,0,0);
        return ans ;
    }
}; 