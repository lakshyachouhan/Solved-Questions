class Solution {
public:
    pair<int,int> bfs( unordered_map<int,list<int>> &adj,int src){

        int farthest = -1;
        int maxLevel = 0 ;
        queue<pair<int,int>> q ;
        q.push({src,0});
        unordered_map<int,bool> vis ;
        vis[src] = true ;

        while(!q.empty()){

                auto front = q.front();
                q.pop();

                int node = front.first ;
                int level = front.second ;

                farthest = node ;
                maxLevel = max(maxLevel,level);
                
                for(auto nbr:adj[node]){

                    if(!vis[nbr]){
                        q.push({nbr,level+1});
                        vis[nbr] = true ;
                    }
                }
        }

        return {farthest,maxLevel};
    }

    int diameter(unordered_map<int,list<int>> &adj){

       // pehle kisi bhi node se diameter ka endpoint find 
       // kisi bhi node se farthest distance wala 
        //    {ek leaf node milegi}
       auto [farthest,level] = bfs(adj,0);

        // phir usse diameter ka dusra endpoint find + diameter
       auto [f2,ans] = bfs(adj,farthest);

       return ans ; 
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        unordered_map<int,list<int>> adj1 , adj2 ;
        for(auto i:edges1){
            int u = i[0] , v = i[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto i:edges2){
            int u = i[0] , v = i[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // diameter -> max. distance 
        // is tarah se join krna hai ki voh min. ho
        int d1 = diameter(adj1);
        int d2 = diameter(adj2);
        
        // dono ke middle point se join 
        // jo divide kr rha hai equal heights mein 
        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1,d2,combined});
    }
};