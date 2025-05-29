class Solution {
public:
    int dfs(unordered_map<int,list<int>> &adj,int src,int parent,int k){

        if(k < 0)
            return 0 ;

        int ans = 1 ; // curr 
        for(auto nbr:adj[src]){

            if(parent != nbr)
                ans += dfs(adj,nbr,src,k-1);
        }

        return ans ;
    }


    vector<int> solve(vector<vector<int>>& e, int k){

        unordered_map<int,list<int>> adj ;
        for(auto &i:e){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(e.size()+1) ;
        for(int i=0; i<=e.size(); i++){

            ans[i] = dfs(adj,i,-1,k);
        }

        return ans ;
    }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        vector<int> ans1 = solve(edges1,k);
        vector<int> ans2 = solve(edges2,k-1); // ek edge join mein lag gyi 

        int maxi = *max_element(ans2.begin(),ans2.end());
        // jis node ka bho maximum hai , sabko usse hi join krnege 

        for(auto &ele:ans1)
            ele += maxi ;

        return ans1 ;
    }
};