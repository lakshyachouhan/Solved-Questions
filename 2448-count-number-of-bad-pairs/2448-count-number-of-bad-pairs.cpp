#define ll long long 
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        // j - i != nums[j] - nums[i]
        // ( nums[i] - i ) != ( nums[j] - j ) 

        unordered_map<ll,ll> mp;
        ll ans = 0 ;
        ll n = nums.size();

        for(int i=0; i<n; i++){

            int curr = nums[i] - i ;

            if(mp.count(curr)){

                // toh curr wale ko - krke jitne bache saare add
                // abhi tak kitne total honge -> i 
                ans += i - mp[curr];
            }

            else ans += i ; // sabke saath pair form 

            mp[curr]++;
        }

        return ans ;        
    }
};