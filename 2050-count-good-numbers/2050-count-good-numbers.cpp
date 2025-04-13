#define ll long long 

class Solution {
public:
    ll MOD = 1e9 + 7 ;
    ll power(ll a,ll b){

        ll ans = 1 ;
        while(b > 0){

            if(b&1){
                ans = (ans * a%MOD)%MOD ;
            }

            a = (a*a)%MOD ;
            b >>= 1 ;
        }
        
        return ans ;
    }

    int countGoodNumbers(long long n) {
        
        ll even = (n+1)/2 ;
        ll odd = n - even ; // odd positions 

        // even pos -> 0,2,4,6,8
        // odd pos -> 2,3,5,7

        ll ans = power(5,even)%MOD * power(4,odd)%MOD ;
        ans %= MOD ;

        return ans ;
    }
};