#define ll long long 

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        ll ans = 0 ;
        int i = 0 ; 

        while(i < nums.size()){

            if(nums[i] == 0){
                int j = i+1; 

                while(j < nums.size() && nums[j] == 0)
                    j++;

                ll zero = j-i ;
                ll  count = (zero * (zero+1))/2 ;
                ans += count ;

                i = j+1 ;
            }

            else i++;
        }

        return ans ;
    }
};