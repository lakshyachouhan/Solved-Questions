#define ll long long 

class Solution {
public:
    int MOD = 1e9 + 7 ;

    ll apowb(ll a,ll b){

        a %= MOD ;
        b %= MOD ;
        
        ll ans = 1 ;
        while(b){

            if(b&1)
                ans = (ans * a)%MOD ;

            a = (a*a)%MOD ;
            b >>= 1 ; 
        }

        return ans ;
    }

    int countGoodArrays(int n, int m, int k) {
        
        // n sizes , k pairs , so k+1 elements should be same 
        // remaining n-(k+1) = n-k-1 elements differnt 
        // m * (m-1)^(n-k-1) * 
        /// total groups = n-k-1 + 1(for equal) = n-k
        // but n is also reduced by 1 
        // but permuataions of above groups = n-1 C n-k-1
        // or n-1 C k // formula n C n-r

        ll ans = (m%MOD * apowb(m-1,n-k-1)%MOD)%MOD ;

        vector<ll> fact(n+1,1);
        for(int i=1; i<=n; i++)
            fact[i] = (fact[i-1] * i%MOD)%MOD ;

        vector<int> inv(n+1,1);
        for(int i=0; i<=n; i++){

            inv[i] = apowb(fact[i],MOD-2)%MOD;
        }

        ans = ((ans * fact[n-1]%MOD)%MOD * inv[n-1-k])%MOD * inv[k] ;
        return ans%MOD ; 
        

    }
};