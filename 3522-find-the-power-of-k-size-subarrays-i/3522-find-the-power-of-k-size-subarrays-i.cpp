class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n-k+1,-1) ;
        int consecutiveCount = 1 ;
        // count of elements in the window

        if(k == 1)  ans[0] = nums[0];

        for(int i=1; i<n; i++){

            if(nums[i] == nums[i-1]+1)  consecutiveCount++;
            else consecutiveCount  = 1 ;
            
            if(consecutiveCount >= k){

                ans[i-k+1] = nums[i];
            }
        }

        return ans ;
    }
};