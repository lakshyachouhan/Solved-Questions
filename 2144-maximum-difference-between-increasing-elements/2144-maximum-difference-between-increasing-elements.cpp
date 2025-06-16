class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int ans = -1 ;
        int n = nums.size();
        int maxi = nums[n-1];

        for(int i=n-2; i>=0; i--){

            ans = max(ans,maxi-nums[i]);
            maxi = max(maxi,nums[i]);
        }

        return ans == 0 ? -1 : ans ;
    }
};