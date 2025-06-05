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

    void unionByRank(int u ,int v){

        int pu = findParent(u) , pv = findParent(v);
        // make parent according to lexo order

        if(pu != pv){

            if(pv < pu)   parent[pu] = pv;
            else if(pv > pu)  parent[pv] = pu;
            else{
                // not run in any case 
                parent[pv] = pu;
                rank[pv]++;
            }
        }
    }

};



class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        DSU ds(26);

        for(int i=0; i<s1.size(); i++){

            ds.unionByRank(s1[i]-'a',s2[i]-'a');
        }

        for(auto &ch:baseStr){

            int p = ds.findParent(ch-'a');
            ch = 'a' + p ;
        }

        return baseStr ;
    }
};