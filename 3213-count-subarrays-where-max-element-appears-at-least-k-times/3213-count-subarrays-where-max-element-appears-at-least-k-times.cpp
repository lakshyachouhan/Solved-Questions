#define ll long long 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        ll ans = 0 ;
        int maxi = *max_element(nums.begin(),nums.end());

        int count = 0 ;
        int i = 0 , j = 0 ;
        int n = nums.size();
    
        while(j < n){

            if(nums[j] == maxi) count++;

            while(count >= k){
                ans += n-j ;
                if(nums[i] == maxi) count--;
                i++;
            }  

            j++;
        }

        return ans ;
    }
};