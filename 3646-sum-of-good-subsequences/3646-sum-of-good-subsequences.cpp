#define ll long long 
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        
        unordered_map<ll,ll> freq; 
        unordered_map<ll,ll> eleSums ;
        ll ans = 0 ;
        ll MOD = 1e9+7 ;

        for(ll i=0; i<nums.size();i++){

            ll curr = nums[i];
            freq[curr] = (freq[curr]+1)%MOD;
            ll sum = curr ;

            if(freq.count(curr-1)){
                sum = (sum%MOD + (curr%MOD)*(freq[curr-1])%MOD)%MOD;
                sum = (sum + eleSums[curr-1]%MOD)%MOD;
                freq[curr] =( freq[curr]%MOD + freq[curr-1]%MOD)%MOD;
            }

            if(freq.count(curr+1)){
                sum = (sum%MOD + (curr%MOD)*(freq[curr+1])%MOD)%MOD;
                sum = (sum + eleSums[curr+1]%MOD)%MOD;
                freq[curr] =( freq[curr]%MOD + freq[curr+1]%MOD)%MOD;
            }
 
            eleSums[curr] = (eleSums[curr]%MOD + sum%MOD)%MOD ;
            ans = (ans%MOD + sum%MOD)%MOD ;
        }

        return ans ;
    }
};