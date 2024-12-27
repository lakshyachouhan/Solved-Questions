class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int maxi = values[0] + 0 ;

        int ans = -1000 ;

        for(int i=1; i<values.size(); i++){

            int curr = maxi + values[i] - i ;

            ans = max(ans,curr);
            maxi = max(maxi,values[i]+i);
        }

        return ans ;
    }
};