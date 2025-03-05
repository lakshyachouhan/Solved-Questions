#define ll long long 
class Solution {
public:
    long long coloredCells(int n) {
        
        if(n == 1)
            return 1 ;

        ll ans = 1 ;

        for(int i=2; i<=n; i++){

            ll multiply = 4*(i-1) ;
            ans += multiply ;
        }

        return ans ;    


    }
};