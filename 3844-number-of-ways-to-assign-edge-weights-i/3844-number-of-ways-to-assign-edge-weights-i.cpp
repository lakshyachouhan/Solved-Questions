#define ll long long 

class Solution {
public:
    ll MOD = 1e9 + 7 ;
    ll findH(unordered_map<ll,list<ll>> &adj,ll src,unordered_map<ll,bool> &vis){

        vis[src] = 1 ;
        ll ans = 0 ;

        for(auto nbr:adj[src]){

            if(!vis[nbr]){
                ll curr = findH(adj,nbr,vis);
                ans = max(ans,curr);
            }
        }

        return 1 + ans ;
    }

    // vector<vector<ll>> dp ;
    // ll solve(ll n,ll sum){

    //     if(n == 0)
    //         return sum&1 ;

    //     if(dp[n][sum] != -1)
    //         return dp[n][sum] ;

    //     ll op1 = solve(n-1,sum+1);
    //     ll op2 = solve(n-1,sum+2);

    //     return dp[n][sum] = (op1%MOD + op2%MOD)%MOD ;
    // }

    ll apowerb(ll a,ll b){

        ll ans = 1 ;
        a %= MOD ;
        

        while(b){

            if(b & 1)
                ans = (ans * a)%MOD ;

            a *= a ;
            a %= MOD ;
            b >>= 1 ;
        }

        return ans%MOD ;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<ll,list<ll>> adj ;

        for(auto &i:edges){
            ll u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<ll,bool> vis ;
        ll height = findH(adj,1,vis);
        // cout << "h" <<  height << endl ;

        // dp.resize(height,vector<ll>(2*(height),-1)) ;
        // ll ans = solve(height-1,0); // edges chaiye 

        ll ans = apowerb(2,height-2);
        return ans ;
    }
};