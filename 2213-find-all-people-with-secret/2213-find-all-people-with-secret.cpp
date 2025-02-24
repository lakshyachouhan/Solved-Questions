class DSU{
    public :
    vector<int> parent , rank ;

    DSU(int n){
        rank.resize(n+1,0);
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
        if(pu != pv){

            if(rank[pu] < rank[pv])   parent[pu] = pv;
            else if(rank[pu] > rank[pv])  parent[pv] = pu;
            else{
                parent[pv] = pu;
                rank[pv]++;
            }

        }
    }
};

static bool comp(vector<int>& a,vector<int>& b){

    return a[2] < b[2] ;
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(),meetings.end(),comp);

        DSU ds(n) ;
        ds.unionByRank(0,firstPerson);
        
        for(int i=0; i<meetings.size(); ){
            
            int currTime = meetings[i][2];
            unordered_set<int> currNodes ; // backtrack ke liye agr unhe secret nhi pata toh

            int j = i ;
            while(j < meetings.size() && meetings[j][2] == currTime){
                ds.unionByRank(meetings[j][0],meetings[j][1]);
                currNodes.insert(meetings[j][0]);
                currNodes.insert(meetings[j][1]);
                j++;
            }

            for(auto node:currNodes){

                if(ds.findParent(node) != ds.findParent(0))
                    ds.parent[node] = node ; // reset 
            }

            i = j ;     
        }

        vector<int> ans ;
        for(int i=0; i<n; i++){

            if(ds.findParent(i) == ds.findParent(0))
                    ans.push_back(i);
        }

        return ans ;
    }
};