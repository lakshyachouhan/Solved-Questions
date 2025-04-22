#define ll long long 
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        ll first = 0 ; 
        ll mini = 0 ; 
        ll maxi = 0 ;

        for(auto ele:differences){

            first += ele ;
            mini = min(mini,first);
            maxi = max(maxi,first);
        }

        ll expected = maxi - mini ;
        ll curr = upper - lower + 1 ;
        ll ans =  curr - expected ;

        return ans > 0 ? ans : 0 ;

    }
};