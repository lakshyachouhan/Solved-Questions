class Solution {
public:
    vector<vector<int>> dp ;
    int solve(vector<int>& days, vector<int>& costs,int i,int end){

        while(i<days.size() && end >= days[i])
            i++;

        if(i >= days.size())
            return 0 ;

        if(dp[i][end] != -1)
            return dp[i][end];

        int op1 = costs[0] + solve(days,costs,i+1,days[i]);
        int op2 = costs[1] + solve(days,costs,i+1,days[i]+7-1);
        int op3 = costs[2] + solve(days,costs,i+1,days[i]+30-1);

        return dp[i][end] = min({op1,op2,op3});
    }

    // int solveTab(vector<int>& days, vector<int>& costs){

    //     vector<vector<int>> dp(366,vector<int>(366,0));

    //     for(int i=days.size()-1; i>=0; i--){
    //         for(int end=365; end>=0; end--){

    //             while(i<days.size() && end >= days[i])
    //                   i++;

    //             int op1 = costs[0] + dp[i+1][days[i]];
    //             int op2 = costs[1] + dp[i+1][days[i]+7-1];
    //             int op3 = costs[2] + dp[i+1][days[i]+30-1];

    //             dp[i][end] = min({op1,op2,op3});
    //         }        
    //     }

    //     return dp[0][0];
    // }

    int solveTab(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int op1 = costs[0] + dp[i + 1];

            int j = i;
            while (j < n && days[j] < days[i] + 7) ++j;
            int op2 = costs[1] + dp[j];

            j = i;
            while (j < n && days[j] < days[i] + 30) ++j;
            int op3 = costs[2] + dp[j];

            dp[i] = min({op1, op2, op3});
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        // dp.resize(days.size()+1 ,vector<int> (366,-1));
        // int ans = solve(days,costs,0,0);

        int ans = solveTab(days,costs);
        return ans ;
    }
};