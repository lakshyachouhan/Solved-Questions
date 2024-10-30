class Solution {
public:

    int finalAns = 0 ;
    int dfs(unordered_map<int,list<int>> &adj,string &s,int src,int parent,vector<bool> &vis){

        vis[src] = true ;
        int firstMax = -1 , secondMax = -1 ;
        int ans = 0 ;
        for(auto nbr:adj[src]){

            if(nbr != parent && !vis[nbr]){
                if(s[src] != s[nbr]){
                    int curr = dfs(adj,s,nbr,src,vis);
                    ans = max(ans,curr);

                    if(firstMax < curr){
                        secondMax = firstMax ;
                        firstMax = curr;
                    }
                    else if(secondMax < curr)   secondMax = curr ;

                }
                    
            }
        }

        finalAns = max(finalAns,firstMax+secondMax+1);
        finalAns = max(finalAns,1+ans);
        return 1 + ans ;
    }

    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        unordered_map<int,list<int>> adj ;

        for(int i=1;i<parent.size(); i++){

            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        vector<bool> vis(n,0);
        for(int node=0;node<n;node++){
            
            if(!vis[node])
                dfs(adj,s,node,-1,vis);
        }

        return finalAns ;
    }
};