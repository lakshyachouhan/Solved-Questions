class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int,list<int>> adj ;
        int n = edges.size();
        vector<int> degree(n+1,0);

        for(auto i:edges){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++ , degree[v]++;
        }

        queue<int> q ;
        vector<bool> vis(n+1,0);
        for(int i=1; i<=n; i++){

            if(degree[i] == 1){
                q.push(i);
                vis[i] = 1 ;
            }
        }

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            for(auto nbr:adj[front]){

                degree[nbr]--;
                if(degree[nbr] == 1){
                    q.push(nbr);
                    vis[nbr] = 1 ;
                }  
                
            }

        }

        for(int i=n-1; i>=0; i--){

            int u = edges[i][0] , v = edges[i][1];

            if(!vis[u] && !vis[v]){
                return {u,v};
            }
        }

        return {-1}; // unreachable 

    }
};