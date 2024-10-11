class Solution {
public:
    bool helper(vector<int>& nums, int target, int i) {

        if (target == 0)
            return true;

        if (target < 0 || i >= nums.size())
            return false;

        bool include = helper(nums, target - nums[i], i + 1);
        bool exclude = helper(nums, target, i + 1);

        return include || exclude;
    }

    bool solveMem(vector<int>& nums, int target, int i,
                  vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (target < 0 || i >= nums.size())
            return false;

        if (dp[target][i] != -1)
            return dp[target][i];

        bool include = solveMem(nums, target - nums[i], i + 1, dp);
        bool exclude = solveMem(nums, target, i + 1, dp);

        return dp[target][i] = include || exclude;
    }

    bool solveTab(vector<int>& nums, int target) {

        vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, 0));

        for (int col = 0; col <= nums.size(); col++)
            dp[0][col] = 1;

        for (int curr = 0; curr <= target; curr++) {

            for (int i = nums.size()-1; i >= 0; i--) {
                int include = 0;

                if(curr-nums[i] >= 0)
                    include = dp[curr - nums[i]][i + 1];

                bool exclude = dp[curr][i + 1];

                dp[curr][i] = include || exclude;
            }
        }
        return dp[target][0];
    }

    bool solveTabSO(vector<int>& nums, int target) {

        // vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, 0));
        vector<int> currCol(target+1,0);
        vector<int> nextCol(currCol);

        currCol[0] = 1;
        nextCol[0] = 1 ;
 
                 
                     for (int i = nums.size()-1; i >= 0; i--) {
                         for (int curr = 0; curr <= target; curr++) {
                int include = 0;

                if(curr-nums[i] >= 0)
                    include = nextCol[curr - nums[i]];

                bool exclude = nextCol[curr];

                currCol[curr] = include || exclude;
            }
            nextCol = currCol ;
        }
        return nextCol[target];
    }

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;

        int target = sum / 2;
        // return helper(nums,target,0);

        vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, -1));
        // return solveMem(nums, target, 0, dp);

        return solveTabSO(nums,target);
    }
};