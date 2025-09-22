class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp ;
        int maxi = 0 ;

        for(auto ele:nums){

            mp[ele]++;
            maxi = max(maxi,mp[ele]);
        }

        int ans = 0 ;
        for(auto [ele,occ]:mp){

            if(occ == maxi)
                ans += maxi ;
        }

        return ans ;
    }
};