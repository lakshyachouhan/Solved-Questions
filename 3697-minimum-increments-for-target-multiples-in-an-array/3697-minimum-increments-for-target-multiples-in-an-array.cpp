class Solution {
public:
    int get_cost(int num, vector<int> &target, int mask) {
        int org_num = num;
        int l = 1;
        for (int i = 0; i < target.size(); i++) {
            if (mask >> i & 1 ^ 1) continue;
            l = lcm(l, target[i]);
            if (l >= 1e5) return 1e6;
        }
        num = (num + l - 1) / l * l;
        return num - org_num;
    }
    
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        const int NP = 1e6;
        vector dp(16, NP);
        
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            vector ndp(16, NP);
            for (int m = 0; m < 16; m++) {
                if (dp[m] == NP) continue;
                for (int mm = 0; mm < 16; mm++) {
                    int nm = m | mm;
                    ndp[nm] = min(ndp[nm], dp[m] + get_cost(nums[i], target, mm));
                }
            }
            dp = ndp;
        }
        
        return dp[15];
    }
};