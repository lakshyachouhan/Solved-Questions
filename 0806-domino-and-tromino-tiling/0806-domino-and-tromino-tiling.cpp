class Solution {
public:
    int numTilings(int n) {

        if(n == 1 || n == 2)
            return n ;
        
        // order --> c , b , a 
        int a = 2 , b = 1 ;
        int c = 1 ;
        int MOD = 1e9 + 7 ;
        int ans ;

        for(int i=3; i<=n; i++){

            ans = (2*a%MOD)+c%MOD ;
            ans %= MOD ;
            c = b ;
            b = a ; 
            a = ans ;
            // cout << ans << endl ;
        }

        return ans ;
    }
};