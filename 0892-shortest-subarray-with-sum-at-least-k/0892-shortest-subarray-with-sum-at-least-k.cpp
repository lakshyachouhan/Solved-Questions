class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq; // (prefix_sum, index)
        long long sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // Check if the current prefix sum satisfies the condition
            if (sum >= k) {
                ans = min(ans, i + 1);
            }

            // Maintain the deque: Remove elements that cannot contribute
            while (!dq.empty() && sum - dq.front().first >= k) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }

            // Maintain deque monotonicity: Remove sums that are greater than or equal to the current sum
            while (!dq.empty() && dq.back().first >= sum) {
                dq.pop_back();
            }

            // Add the current prefix sum to the deque
            dq.push_back({sum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
