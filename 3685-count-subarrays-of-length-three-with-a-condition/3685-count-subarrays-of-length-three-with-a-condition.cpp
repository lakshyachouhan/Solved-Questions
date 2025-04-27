class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int n = nums.size() ;
        int ans = 0 ;

        for(int i=0; i<n-2; i++){

            int j=i+1 , k = i+2 ;
            if(2*(nums[i]+nums[k]) == nums[j])
                ans++;

        }

        return ans ;
    }
};