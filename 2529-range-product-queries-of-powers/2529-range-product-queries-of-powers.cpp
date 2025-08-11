#define ll long long 

class Solution {
public:
    ll MOD = 1e9 + 7 ;
    ll apowb(ll a,ll b){

        ll ans = 1 ;
        while(b){

            if(b&1)
                ans = (ans * a)%MOD ;

            a = (a * a )%MOD ;
            b >>= 1 ;
        }

        return ans ;
    }


    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // 2 ki powers se n banana hai 
        // toh jo bits n mein set hai 
        // vo wali powers le lo 
        
        vector<ll> powers ;
        for(int i=0; i<32; i++){

            if(n & (1<<i))
                powers.push_back(1 << i);
        }

        vector<ll> prefix(powers.size());

        ll prod = 1 ;
        for(int i=0; i<powers.size(); i++){

            prod = (prod * powers[i])%MOD;
            prefix[i] = prod ;
        }

        vector<int> ans ;
        for(auto q:queries){

            int s = q[0] , e = q[1];
            ll curr = prefix[e]%MOD;

            if(s-1 >= 0){

                ll inv = apowb(prefix[s-1],MOD-2);
                curr = (curr * inv%MOD) % MOD ;
            }

            ans.push_back(curr);
        }

        return ans ;
    }
};