class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        int ans = 1 ;
        sort(coins.begin(),coins.end());
        for(auto ele:coins){

            if(ele > ans)
                break ;

            ans += ele ;
        }

        return ans ;
    }
};