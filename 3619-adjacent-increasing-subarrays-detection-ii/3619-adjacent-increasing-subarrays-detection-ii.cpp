class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        vector<int> v;
        int count = 0;
        int ans = 0;

        for (int i = 1; i < nums.size(); i++) {
 
            if (nums[i] > nums[i - 1]) count++;

            else {
                // count even hai , matlab length eg count = 2
                // toh leng = 3 , k = 1 = count-1/2
                if (count % 2 == 0) ans = max(ans, (count - 1) / 2);
                else ans = max(ans, count / 2);

                if (!v.empty()) 
                    ans = max(ans, min(count, v.back()));

                v.push_back(count);
                count = 0;
            }
        }

        if (count % 2 == 0) ans = max(ans, (count - 1) / 2);
        else ans = max(ans, count / 2);

        if (!v.empty()) 
            ans = max(ans, min(count, v.back()));

        return ans + 1;
    }
};