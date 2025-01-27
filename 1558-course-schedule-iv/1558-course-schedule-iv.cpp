class Solution {
public:
    bool dfs(unordered_map<int,list<int>> &adj ,int src,int dest,vector<bool> &vis){

        vis[src] = 1 ;

        if(src == dest)
            return true ;

        for(auto nbr:adj[src]){

            if(!vis[nbr]){

                if(dfs(adj,nbr,dest,vis))
                    return 1 ;
            }
        }

        return 0 ;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        unordered_map<int,list<int>> adj ;

        for(auto i:prerequisites){

            int u = i[0] , v = i[1];
            adj[u].push_back(v);
        }

        vector<bool> ans ;
        for(auto i:queries){

            int u = i[0] , v = i[1];
            vector<bool> vis(numCourses,0);
            if(dfs(adj,u,v,vis)){
                ans.push_back(1);
            }

            else ans.push_back(0);
        }

        return ans ;
    }
};