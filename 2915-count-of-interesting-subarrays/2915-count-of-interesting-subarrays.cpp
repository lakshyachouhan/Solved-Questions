#define ll long long 

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // mod == k wale elemetns ko count krna hai 
        // toh pehle sabka mod le lo , usse prefix Sum , mp 
        // jaise dikh gya , ab mp se count ka socho 
        // do counts ka diff%m == k hona chaiye 
        // usse formula 


        ll ans = 0 ;
        unordered_map<int,int> mp ;
        int cnt = 0 ;

        mp[0] = 1 ;

        for(int i=0; i<nums.size(); i++){

            if(nums[i]%modulo == k)
                cnt++;

            int req = (cnt + modulo - k) % modulo ;
            if(mp.count(req))
                ans += mp[req];

            mp[cnt%modulo]++;
        }

        return ans ;
    }
};