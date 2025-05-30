class Solution {
public:
    void bfs(unordered_map<int,list<int>> &adj,int src,vector<int> &d){

        queue<int> q ;
        unordered_map<int,bool> vis ;
        vis[src] = 1 ;
        d[src] = 0 ;
        q.push(src) ;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto nbr:adj[node]){

                if(!vis[nbr]){
                    q.push(nbr);
                    d[nbr] = d[node] + 1 ;
                    vis[nbr] = 1 ;
                }
            }
        }
    }


    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        unordered_map<int,list<int>> adj;

        for(int i=0; i<n; i++){
            int u = i , v = edges[i];

            if(v != -1)
                adj[u].push_back(v);
        }

        vector<int> dist1(n,1e9);
        vector<int> dist2(n,1e9);

        bfs(adj,node1,dist1);
        bfs(adj,node2,dist2);

        int maxi = 1e9 ;
        int ans = -1 ;
        for(int i=0; i<n; i++){

            // cout << i << "  " << dist1[i] << "  " << dist2[i] << endl ;

            int curr = max(dist1[i],dist2[i]);

            if(curr < maxi){
                maxi = curr;
                ans = i ;
            }
        }

        return ans ;

    }
};