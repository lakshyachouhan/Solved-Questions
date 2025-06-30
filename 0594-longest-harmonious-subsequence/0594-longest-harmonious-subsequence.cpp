class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int,int> mp ;
        for(auto ele:nums)
            mp[ele]++;

        int ans = 0; 
        for(auto [ele,f]:mp){

            if(mp.count(ele+1)){
                int curr = f + mp[ele+1];
                ans = max(ans,curr);
            }
        }

        return ans ;
    }
};