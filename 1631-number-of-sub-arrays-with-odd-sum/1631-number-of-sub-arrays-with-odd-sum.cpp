class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        // Question ko ache se samjho 
        // It is same as finding the subarrays having odd no. of odd elements 
        // even - odd = odd 
        // odd - even = odd 
        // only 2 cases , baaki 2 cases mein even hoga which is not required 

        int ans = 0 ;
        int oddCount = 0 ;
        int evenCount = 1 ; // 0 sum 
        int odd = 0 ;
        int MOD = 1e9 + 7 ;

        for(auto &ele:arr){

            if(ele & 1) odd++;
            odd %= 2 ;

            if(odd&1){
                // odd no. of odd elements hai
                ans += evenCount%MOD ; 
                oddCount++;
            }

            else{
                ans += oddCount%MOD ;
                evenCount++;
            } 

            ans %= MOD ;
            oddCount %= MOD ;
            evenCount %= MOD ;
        }

        return ans ;        
    }
};