class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans = 0 ;
        vector<pair<char,int>> v  ;
        v.push_back({colors[0],neededTime[0]});

        for(int i=1; i<colors.size(); i++){

           if(v.back().first == colors[i]){

                ans += min(v.back().second,neededTime[i]);
                v.back().second = max(v.back().second,neededTime[i]);
           }

           else v.push_back({colors[i],neededTime[i]});
        }

        return ans ;
    }
};