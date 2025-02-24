class Solution {
public:
    bool dfsForBob(int src,unordered_map<int,list<int>> &adj, vector<int> &time,int t){

        time[src] = t ;
        if(src == 0 )
            return true ; 

        for(auto nbr:adj[src]){

            if(time[nbr] == -1){

                bool aageKaAns = dfsForBob(nbr,adj,time,t+1);
                if(aageKaAns == 1)
                    return 1 ;
            }
        }

        time[src] = -1 ;
        return false ;        
    }

    int dfs(int src,unordered_map<int,list<int>> &adj, vector<int> &time,int t,vector<int>& amount,unordered_map<int,bool>& vis){

        vis[src] = 1 ;
        int ans = 0 ;
        // cout<< src << "  reached at time " << t << " previousBob " << time[src] << endl ;
        if(time[src] == -1 || time[src] > t){
            // matlab ye pehle aagya bob se 
            ans += amount[src];
        }

        else if(time[src] ==  t)  ans += amount[src]/2 ;

        int aageKaAns = -1e9 ;
        for(auto nbr:adj[src]){

            if(!vis[nbr]){
                int curr = dfs(nbr,adj,time,t+1,amount,vis);
                aageKaAns = max(aageKaAns,curr);
            }
        }

        if(aageKaAns != -1e9)
            return aageKaAns + ans ;

        return ans ;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = edges.size();
        vector<int> time(n+1,-1);

        unordered_map<int,list<int>> adj ;
        for(auto i:edges){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfsForBob(bob,adj,time,0);

        unordered_map<int,bool>  vis ;
        int ans = dfs(0,adj,time,0,amount,vis);
        return ans ;
    }
};