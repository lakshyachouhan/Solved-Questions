class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int ans = 0 ;
        int n = nums.size();

        for(int i=0; i< (1<<n); i++){

            int curr = 0 ;
            for(int j=0; j<n; j++){

                // jth bit in i 
                if(i & (1<<j)){
                    curr ^= nums[j];
                }
            }

            ans += curr ;
        }

        return ans ;
    }
};