class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        map<int,int> mp ;
        for(auto ele:nums){

            mp[ele-k]++;
            mp[ele+k+1]--;
        }

        int ans = 1 ;
        int curr = 0 ;

        for(auto [ele,occ]:mp){

            curr += occ ;
            ans = max(ans,curr);
        }

        return ans ;
    }
};