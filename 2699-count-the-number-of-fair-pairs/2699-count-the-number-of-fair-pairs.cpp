class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        

        long long ans = 0 ;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){

            auto lb = lower_bound(nums.begin()+(i+1),nums.end(),lower-nums[i]);
            auto ub = upper_bound(nums.begin()+(i+1),nums.end(),upper-nums[i]);
            ans += ub-lb ;
        }

        return ans ;
    }
};