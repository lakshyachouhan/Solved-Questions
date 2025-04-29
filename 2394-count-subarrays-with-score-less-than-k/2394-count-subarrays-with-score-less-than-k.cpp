#define ll long long 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        ll ans = 0 ;
        int i = 0 , j =  0;
        ll sum = 0 ;

       // each step pr ans le rhe hai  
        while(j < nums.size()){

            sum += nums[j];

            // agr invalid toh minimise 
            while(1LL * sum * (j-i+1) >= k){

                sum -= nums[i];
                i++;
            }

            ans += j-i+1 ;
            j++;
        }

        return ans ;
    }
};