class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 0 ;
        int count = 0 ;

        for(int ele:nums){

            if(ele == maxi) count++;
            else count = 0 ;

            ans = max(ans,count);
        }

        return ans ;
    }
};