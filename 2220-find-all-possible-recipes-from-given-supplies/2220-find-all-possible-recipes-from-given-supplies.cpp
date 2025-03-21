class Solution {
public:
    bool dfs(unordered_map<string, list<string> > &adj,string src,unordered_map<string,bool> &vis){

        // agr already vis hai toh return krdo : bn skti ya nhi ban skti 
        if(vis.count(src))
            return vis[src]; 

        if(adj.count(src) == 0)
            return vis[src] = 0 ;

        vis[src] =  0;

        bool ans = 1;
        for(auto nbr:adj[src]){

            if(!dfs(adj,nbr,vis))
                ans = 0 ;

        }

        return vis[src] = ans ;
    }


    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, list<string> > adj ;
        int n = recipes.size() ;

        for(int i=0; i<n; i++){

            string u = recipes[i];
            for(auto v:ingredients[i]){
                adj[u].push_back(v);
            }
        }

        
        unordered_map<string,bool> vis ;
        // 0 -> Visited 
        // 1 -> Visited + Possible to make 
        
        for(auto s:supplies)
                vis[s] = 1 ;


        vector<string> ans ;
        for(auto s:recipes){

            dfs(adj,s,vis);

            if(vis[s] == 1)
                ans.push_back(s);
        }

        return ans ;

    }
};