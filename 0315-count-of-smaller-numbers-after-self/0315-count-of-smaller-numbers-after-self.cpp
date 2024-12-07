class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<int> sorted(nums);
        vector<int> ans ;
        sort(sorted.begin(),sorted.end());

        for(auto ele:nums){

            auto lb = lower_bound(sorted.begin(),sorted.end(),ele);
            int index = lb - sorted.begin();
            ans.push_back(index);

            sorted.erase(lb);
        }

        return ans ;
    }
};