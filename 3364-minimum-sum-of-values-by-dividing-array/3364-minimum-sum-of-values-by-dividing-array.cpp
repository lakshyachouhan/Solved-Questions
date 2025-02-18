class Solution {
public:
//   T.C O(N^2 * M )
    // vector<vector<int>> dp ;
    // int solve(vector<int>& nums, vector<int>& andValues,int i,int andi){

    //     if(i >= nums.size() && andi >= andValues.size())
    //         return 0 ;

    //     if(i >= nums.size() || andi >= andValues.size())
    //         return 1e7 ;

    //     if(dp[i][andi] != -1)
    //         return dp[i][andi] ;

    //     int ans = 1e7 ;
    //     int val = -1 ;
    //     for(int index=i; index<nums.size(); index++){

    //         if(val == -1)   val = nums[index];
    //         else val &= nums[index] ;

    //         if(val == andValues[andi]){
    //             int curr = nums[index] + solve(nums,andValues,index+1,andi+1);
    //             ans = min(ans,curr);
    //         }
    //     }

    //     return dp[i][andi] = ans ;
    // }

//  T.C O(N * M)
     vector<vector<unordered_map<int,int>>> dp;
    int solve(vector<int>& nums, vector<int>& andValues, int i, int andi, int currVal) {
        if (i >= nums.size() && andi >= andValues.size())
            return 0;

        if (i >= nums.size() || andi >= andValues.size())
            return 1e7;

        if (dp[i][andi].count(currVal))
            return dp[i][andi][currVal];

        int include = 1e7;
        int newVal = (currVal == -1) ? nums[i] : (currVal & nums[i]);

        if (newVal == andValues[andi])
            include = nums[i] + solve(nums, andValues, i + 1, andi + 1, -1);

        int exclude = solve(nums, andValues, i + 1, andi, newVal);

        return dp[i][andi][currVal] = min(include, exclude);
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        
        // dp.resize(nums.size()+1,vector<int>(andValues.size()+1,-1));
        //  int ans = solve(nums,andValues,0,0);

         dp.resize(nums.size() + 1, vector<unordered_map<int, int>>(andValues.size() + 1));
        int ans = solve(nums,andValues,0,0,-1);

        return ans >= 1e7 ? -1 : ans ;
    }
};