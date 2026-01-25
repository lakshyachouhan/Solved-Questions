class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        if(k == 1)
            return 0 ;

        sort(nums.begin(),nums.end());
        int ans = 1e9 ;

        for(int i=k-1; i<nums.size(); i++){

            int diff = nums[i] - nums[i-k+1];
            ans = min(ans,diff);
        }

        return ans ;
    }
};