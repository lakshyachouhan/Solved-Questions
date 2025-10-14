class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        for(int i=0; i<=n-2*k; i++){

            bool f = 1 ;
            for(int j=i; j<i+k-1; j++){

                if(nums[j+1] <= nums[j]){
                    f = 0 ;
                    break ;
                }
            }

            if(f == 0) continue ;
            for(int j=i+k; j<i+2*k-1; j++){

                if(nums[j+1] <= nums[j]){
                    f = 0 ;
                    break ;
                }
            }

            if(f)
                return true ;
        }

        return false ;
    }
};