class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
        vector<int> ans ;
        sort(nums.rbegin(),nums.rend());
        unordered_map<int,bool> mp ;

        for(auto ele:nums){

            if(mp.count(ele) == 0){
                mp[ele] = 1 ;
                ans.push_back(ele);
            }

            if(ans.size() == k)
                return ans ;
        }

        return ans ;
    }
};