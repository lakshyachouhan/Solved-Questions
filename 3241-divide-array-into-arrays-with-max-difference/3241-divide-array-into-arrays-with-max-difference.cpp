class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans ;
        vector<int> build(3,-1);

        int bi = 0 ;
        for(auto ele:nums){

            build[bi++] = ele ;

            if(bi == 3){

                if(build[2] - build[0] > k)
                    return {};

                ans.push_back(build);
                bi -= 3 ;
            } 
        }

        return ans ;
    }
};