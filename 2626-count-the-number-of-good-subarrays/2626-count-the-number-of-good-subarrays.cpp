#define ll long long 

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        ll ans = 0 ;
        int n = nums.size() ;
        int i = 0 , j = 0 ;
        int pairs = 0 ;
        unordered_map<int,int> mp ;

        while(j < n){
            
            // pehle jitni baar nums[j] , sab ke saath pair form
            if(mp.count(nums[j]))
                pairs += mp[nums[j]];

            mp[nums[j]]++;

            while(pairs >= k){
                // minimise the window 
                ans += n-j ;  // aage ke jitne poore add
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return ans ;
    }
};