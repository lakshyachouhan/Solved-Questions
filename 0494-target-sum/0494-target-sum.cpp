class Solution {
public:
     int solve(vector<int>& nums, int target,int i,int sum){

        if(i >= nums.size()){
            if(target == sum)   return 1 ;
            else return 0 ;
        }

        int add = solve(nums,target,i+1,sum+nums[i]);
        int sub = solve(nums,target,i+1,sum-nums[i]);

        return add + sub ;
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solve(nums,target,0,0);
        return ans ;
    }
};