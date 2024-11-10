class Solution {
public:
    bool check(vector<int>& count, int k) {
        int num = 0;
        for(int i = 0; i < 32; i++) {
            if(count[i] > 0) {
                num |= (1 << i);
            }
        }
        return num >= k;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = nums.size() + 1;
        int i = 0, j = 0;
        vector<int> count(32, 0);
        
        while(j < nums.size()) {

            for(int bit = 0; bit < 32; bit++) {

                bool b = nums[j] & (1 << bit) ;
                if(b) {
                    count[bit]++;
                }
            }
            
            while(i <= j && check(count, k)) {
                ans = min(ans, j - i + 1);
                
                for(int bit = 0; bit < 32; bit++) {
                    bool b = nums[i] & (1 << bit) ;
                    if(b) {
                        count[bit]--;
                    }
                }
                i++;
            }
            j++;
        }
        
        return ans == nums.size() + 1 ? -1 : ans;
    }
};
