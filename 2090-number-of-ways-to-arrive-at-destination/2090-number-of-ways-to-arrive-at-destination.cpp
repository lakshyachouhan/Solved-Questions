#define ll long long

class Solution {
public:
    
    ll dijkstra(int n,unordered_map<int,list<pair<int,int>> > &adj,int src,int dest){

        vector<ll> dist(n,LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > minHeap ;
        minHeap.push({0,src});

        vector<ll> dp(n,0);
        dp[0] = 1 ;
        ll MOD = 1e9 + 7 ;

        // map<ll,ll> mp ; // ordered map toh jo chota uski freq return
        // minHeap ko update krte time equal wale bhi push
        // to count all paths
        // DRY RUN -> dijkstra -> ans kaise milega  
        // return mp.begin()->second ;

        while(!minHeap.empty()){

            auto [distSrc,node] = minHeap.top();
            minHeap.pop();

            if(distSrc > dist[node])
                continue; // jab distance updated nhi hai pq wala toh check se koi matlab nhi
            
            for(auto [nbr,wt]:adj[node]){

                if(dist[node] + wt < dist[nbr]){
                    dp[nbr] = dp[node]%MOD ;
                    dist[nbr] =  dist[node] + wt ;
                    minHeap.push({dist[nbr],nbr});
                }

                else if(dist[node] + wt == dist[nbr]){
                    dp[nbr] = (dp[nbr]+dp[node])%MOD;
                }
            }

        }

        return dp[dest] ; // n-1

    }

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,list<pair<int,int>> > adj ;

        for(auto i:roads){
            int u = i[0] , v = i[1] , wt = i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int ans = dijkstra(n,adj,0,n-1);
        return ans ;
    }
};