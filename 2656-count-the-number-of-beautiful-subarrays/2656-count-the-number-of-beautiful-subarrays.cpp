#define ll long long 
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        // que ko samjho : koi do no. lene hai jisme kth bit 1 hai 
        // toh unki kth bit ko 0 krdo 
        // All elemets are 0 -> matlab saari bits ko 0 krna hai , even honi chaiye 
        // toh isse bitwise ki intution mili , phir SW se dekha 
        // lekin  usse ans nhi aarha tha 
        // toh running sum leke , mp se krke dekha 

        unordered_map<ll,ll> mp ;
        mp[0] = 1 ;
        ll ans = 0 ;
        ll number = 0 ;

        for(auto &ele:nums){

            number ^= ele ;
            ans += mp[number];
            mp[number]++;
        }

        return ans ;
    }
};