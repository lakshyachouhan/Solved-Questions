class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans = 1 ;
        int count = 1 ;

        for(int i=0; i<nums.size()-1; i++){

            if(nums[i] < nums[i+1])
                count++;

            else count = 1 ;

            ans = max(ans,count);
        }

        count = 1  ;
         for(int i=0; i<nums.size()-1; i++){

            if(nums[i] > nums[i+1])
                count++;

            else count = 1 ;

            ans = max(ans,count);
        }

        return ans ;
    }
};