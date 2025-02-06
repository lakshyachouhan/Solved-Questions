class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        
        int ans = 0;
        for(auto& [product, count] : mp) {
            
            // Number of tuples for this product
            // Each set of pairs can form 8 unique tuples
            int set = count * (count - 1)/2 ;
            ans +=  set * 8;
        }
        
        return ans;
    }
};