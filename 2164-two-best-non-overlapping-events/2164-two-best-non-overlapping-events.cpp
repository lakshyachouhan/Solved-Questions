class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    //    {endTime,val}
    // kyoki sorted hai toh startTime hamesha increasing order mein hi hoga 
    // ab endTime ko bas check 

        int maxValue = 0;
        int ans = 0;

        for (auto& event : events) {
            int startTime = event[0];
            int endTime = event[1];
            int value = event[2];

            while (!minHeap.empty() && minHeap.top().first < startTime) {
                maxValue = max(maxValue, minHeap.top().second);
                minHeap.pop();
            }

            ans = max(ans, maxValue + value);
            minHeap.push({endTime, value});
        }

        return ans;
    }
};
