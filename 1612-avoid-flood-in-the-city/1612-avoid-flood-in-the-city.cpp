class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        vector<int> ans(n, 1); 
        unordered_map<int,int> last; // lake -> last day index it rained
        set<int> dry; // indices of dry days (ordered)

        for (int i = 0; i < n; ++i) {

            int lake = rains[i];
            if (lake > 0) {

                ans[i] = -1;

                if (last.find(lake) != last.end()) {

                    // we must dry this lake after its last rain day
                    int requiredAfter = last[lake] + 1;
                    auto it = dry.lower_bound(requiredAfter);

                    if (it == dry.end()) {
                        return {};
                    }

                    ans[*it] = lake;
                    dry.erase(it);
                }

                last[lake] = i;
            } 
            
            else {
                dry.insert(i);
            }

        }
        
        return ans;
    }
};
