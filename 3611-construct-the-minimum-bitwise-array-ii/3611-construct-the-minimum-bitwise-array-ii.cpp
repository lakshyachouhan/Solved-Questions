class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans ;

        for(auto &ele:nums){

            if(ele == 2){
                ans.push_back(-1);
                continue ;
            }

            int num = ele ;
            int count = 0 ;

            while(num&1 == 1){
                count++;
                num >>= 1 ;
            }

            
            // [count]th bit is the position of the last 1, like 100111 (count = 3)
            // Subtract the bit

            ele -= (1 << (count-1));
            ans.push_back(ele);
        }

        return ans ;
    }
};