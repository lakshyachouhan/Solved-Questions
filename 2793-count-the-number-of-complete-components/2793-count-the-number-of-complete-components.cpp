class DSU{
    public :
    vector<int> parent , rank , size;

    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
            parent[i] = i ;
    }

    int findParent(int node){
        if(parent[node] == node)
           return node ;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u ,int v,int currCost){

        int pu = findParent(u) , pv = findParent(v);

        if(pu != pv){
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }   

            else{
                parent[pv] = pu;
                rank[pv]++;
            }
        }

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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        // agr connected component ka size k hai 
        // toh hr node ki degree k-1 honi chaiye 
        // for it is to be a complete component 

        DSU ds(n);
        vector<int> degree(n,0);

        for(auto &i:edges){

            int u = i[0];
            int v = i[1];

            ds.unionBySize(u,v);
            degree[u]++;
            degree[v]++;
        }

        int ans = 0 ;
        unordered_map<int,bool> parents ;

        for(int i=0; i<n; i++){

            int p = ds.findParent(i);

            if(parents.count(p) == 0)  // not present 
                parents[p] = 1 ; // initially complete component

            if(degree[i] != ds.size[p] - 1)
                parents[p] = 0 ;
        }

        for(auto &[p,s]:parents){

            if(s == 1)
                ans++;
        }

        return ans ;
    }
};