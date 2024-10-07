class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int> firstOcc ;
        int ans =  1e9 ;

        for(int i=0; i<cards.size(); i++){

            int val = cards[i];
            if(firstOcc.count(val) == 0)
                firstOcc[val] = i ;

            else{
                ans = min(ans,i-firstOcc[val]);
                firstOcc[val] = i ;
            }
        } 

        return ans != 1e9 ? ans+1 : -1 ;
    }
};