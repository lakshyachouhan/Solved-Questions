// Cost aur add karo for the parents 
class DSU{
    public :
    vector<int> parent , rank , size;
    vector<int> cost; 

    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        cost.resize(n,-1); // -1 -> 11111.....111

        for(int i=0; i<=n; i++)
            parent[i] = i ;
    }

    int findParent(int node){
        if(parent[node] == node)
           return node ;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u ,int v,int currCost){

        // yha main code hai cost ka ...
        int pu = findParent(u) , pv = findParent(v);

        if(pu != pv){
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
                cost[pv] &= cost[pu];
            }   

            else{
                parent[pv] = pu;
                rank[pv]++;
                cost[pu] &= cost[pv];
            }
        }

        cost[parent[pu]] &= currCost ; 
        // jo bhi final parent usme AND 

    }

    void unionBySize(int u ,int v){
        int pu = findParent(u) , pv = findParent(v);
        if(pu != pv){
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    }
};




class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        // cost minimum krna hai 
        // kab hoga -> AND se hamesha value less ya equal hogi 
        // toh jitna jyada AND operations kr skte hai , do that

        DSU ds(n) ;
        
        for(auto i:edges){

            int u = i[0] , v = i[1] , w = i[2] ;
            ds.unionByRank(u,v,w);           
        }

        vector<int> ans ;
        for(auto i:query){

            int s = i[0] , e = i[1];

            if(s == e)  ans.push_back(0);
            else if(ds.findParent(s) != ds.findParent(e))
                ans.push_back(-1);

            else ans.push_back(ds.cost[ds.findParent(s)]);
        }

        return ans ;
    }
};