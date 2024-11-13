class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k == 1)  return true ;

        for(int i=0; i<=n-2*k; i++){
            
            int p = k-1 ;
            bool f = 1 ;
            int j = i+1 ;
            for(; j<n && p; j++){
                
                if(nums[j] <= nums[j-1]){
                    f = 0 ;
                    break ;
                }

                p--;
            }
            
            p = k-1 ;
            j++;
            for(; j<n && p; j++){
                
                if(nums[j] <= nums[j-1]){
                    f = 0 ;
                    break ;
                }

                p--;
            }

            if(f)   return true ;    
        }

        return false ;

    }
};