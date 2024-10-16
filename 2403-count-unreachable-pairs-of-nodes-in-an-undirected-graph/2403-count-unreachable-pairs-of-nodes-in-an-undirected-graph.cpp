#define ll long long 
class Solution {
public:
    ll dfs(unordered_map<int,list<int>> &adj,int src,vector<bool> &vis){
        vis[src] = true ;

        ll curr = 1 ;

        for(auto nbr:adj[src]){

            if(!vis[nbr]){
                curr += dfs(adj,nbr,vis);
            }
        }

        return curr ;
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<ll> counts ;
        unordered_map<int,list<int>> adj ;

        for(auto &i:edges){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        ll sum = 0;
        for(int node=0; node<n; node++){

            if(!vis[node] ){
                ll curr = dfs(adj,node,vis);
                counts.push_back(curr);
                sum += curr ;
            }
        }

        ll ans = 0 ;
        for(auto i:counts)  cout << i << " " ;

        for(int i=0; i<counts.size(); i++){
                
                sum -= counts[i];
                ans += counts[i] * (sum);

        }

        return ans ;

    }
};