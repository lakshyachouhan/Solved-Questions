class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        unordered_map<int,int> left, right ;
        int MOD = 1e9 + 7 ;
        int ans = 0 ;

        for(int i=0; i<nums.size(); i++){

            int val = nums[i] ;
            right[val]++;
        }

        // iterate from the leftmost
        // and build left vector/ map
        for(int i=0; i<nums.size(); i++){

            int req = nums[i]*2 ;
            right[nums[i]]--;

            long long curr = (1LL * left[req]%MOD * right[req]%MOD)%MOD;
            ans = (ans + curr)%MOD ;

            left[nums[i]]++;
        }

        return ans ;
    }
};