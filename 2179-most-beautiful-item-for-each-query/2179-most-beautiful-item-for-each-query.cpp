class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(items.begin(), items.end());
        map<int, int> mp;
        int maxi = -1;

        for(auto &i : items) {
            maxi = max(maxi, i[1]);
            mp[i[0]] = maxi;
        }

        vector<int> ans;

        for(auto i : queries) {

            auto it = mp.upper_bound(i);
            if (it == mp.begin()) 
                    ans.push_back(0);
            
            else {
                it--;
                ans.push_back(it->second);
            }

        }

        return ans;
    }
};
