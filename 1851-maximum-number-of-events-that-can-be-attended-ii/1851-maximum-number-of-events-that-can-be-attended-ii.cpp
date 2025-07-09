class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& events, int i, int k, vector<int>& startTimes) {
        if (k <= 0 || i >= n)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int value = events[i][2];

        // 1D array B.S Accepted
        // 3D array B.S TLE  ,  temp  = {end,1e9,1e9};
        int next = lower_bound(startTimes.begin(), startTimes.end(), events[i][1] + 1) - startTimes.begin();

        int take = value + solve(events, next, k - 1, startTimes);
        int skip = solve(events, i + 1, k, startTimes);

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        n = events.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));

        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i)
            startTimes[i] = events[i][0];

        return solve(events, 0, k, startTimes);
    }
};
