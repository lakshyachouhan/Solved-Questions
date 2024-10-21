class DSU{
    public:
    vector<int> parent,rank ;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i ;
    }

    int findP(int i){

        if(parent[i] == i)  return i ;
        return parent[i] = findP(parent[i]);
    }

    void unionByRank(int v,int u){
        int ulu = findP(u) , ulv = findP(v) ;

        if(rank[ulu] < rank[ulv]){
            parent[ulu] = ulv ;
        }
        else{
            parent[ulv] = ulu ;
            rank[ulu]++;
        }
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int> emailParent;

        for(int i=0; i<accounts.size(); i++){
            
            for(int j=1; j<accounts[i].size(); j++){

                auto e = accounts[i][j] ;
                if(emailParent.count(e) != 0){
                    ds.unionByRank(i,emailParent[e]);
                }

                emailParent[e] = i ;
            }
        }

        map<int,set<string>> mp ;
        for(auto &[e,p] : emailParent){

            auto ulp = ds.findP(p);
            mp[ulp].insert(e);
        }

        vector<vector<string>> ans ;
        for(auto &[index,st]:mp){

            vector<string> curr ;
            curr.push_back(accounts[index][0]);
            for(auto &ele:st)   curr.push_back(ele);

            ans.push_back(curr);
        }

        return ans ;
    }
};