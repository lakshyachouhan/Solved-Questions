class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> prime(maxi + 1, 0);
        set<int> st;

        for (int i = 2; i <= maxi; i++) {

            if (prime[i] == 0) {

                st.insert(i);
                for (int j = 2 * i; j <= maxi; j += i) {
                    prime[j] = 1;
                }

            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];

            if (i == 0 || ele > nums[i - 1]) {
                auto it = st.lower_bound(nums[i]);
                if (it != st.begin()) it--;


                // reduce to just greater value than previus element
                while (i != 0 && ele - *it <= nums[i - 1] && it != st.begin()) {
                    it--;
                }

                // agr reduce ke baad bada hai toh assign , vrna keep original
                if (ele - *it > (i == 0 ? 0 : nums[i - 1])) {
                    nums[i] = ele - *it;
                }
            } 
            
            else  return false;
        }

        return true;
    }
};
