class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k == 0)
            return 0 ;

        int ans = 0 , i = 0 , j = 0 ;
        long long product = 1 ;
        while(j < nums.size()){

            product *= nums[j];

            while(i<j && product >= k){
                product /= nums[i];
                i++;
            }

            if(product < k)
                 ans += j-i+1  ;

            j++;
        }

        return ans ;
    }
};