class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> ans ;
        int xor_total = 0 ;

        for(auto i:nums)
            xor_total ^= i ;

        int n = nums.size();
        int maxi = xor_total ^ ((1<<maximumBit)-1) ;
        // first / intial wala answer calculate 
        ans.push_back(maxi);

        for(int i=0; i<n-1; i++){

            xor_total ^= nums.back();
            nums.pop_back();
            int curr = xor_total ^ ((1<<maximumBit)-1) ; 

            ans.push_back(curr);
        }

        return ans ;
    }
};