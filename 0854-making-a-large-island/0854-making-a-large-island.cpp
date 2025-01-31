class DSU{
public:
    vector<int> parent,size ;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0; i<=n; i++) 
            parent[i] = i ;
    }

    int findP(int node){

        if(parent[node] == node)
            return node ;

        // path Compression
        return parent[node] = findP(parent[node]);
    }

    void unionBySize(int u,int v){

        if(findP(u) == findP(v))    return ;

        int ulu = findP(u) , ulv = findP(v) ;
        if(size[ulu] < size[ulv]){
            size[ulv] += size[ulu];
            parent[ulu] = ulv ;
        }

        else{
            size[ulu] += size[ulv];
            parent[ulv] = ulu ;
        }
    }

};



class Solution {
public:
    int convert(int i,int j,int n){

        return n * i + j ;
    }

    void dfs(vector<vector<int>>& grid,int srcX,int srcY,DSU &ds, vector<vector<bool>> &vis){

        vis[srcX][srcY] = 1 ;
        int n = grid.size();

          int dx[] = {-1,0,1,0};
          int dy[] = {0,1,0,-1};

            for(int k=0; k<4; k++){

                        int newX = dx[k] + srcX ;
                        int newY = dy[k] + srcY ;

                        if(newX >=0 && newY>=0 && newX<n && newY<n && grid[newX][newY] == 1 && !vis[newX][newY]){
                            
                           ds.unionBySize(convert(srcX,srcY,n),convert(newX,newY,n));
                        }

                    }

    }

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DSU ds(n*n) ;

        vector<vector<bool>> vis(n,vector<bool>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(!vis[i][j] && grid[i][j] == 1){

                    dfs(grid,i,j,ds,vis);
                    // jitne 1's wale the sb ke grp ban chuke hai
                }
            }
        }

        // for(int i=0; i<n*n; i++){
            // cout << i << "   " << ds.size[i]  << ", ";
        // }

        int ans = 0;
        // ab zeros find karo & 1 mein  change kro 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                int dx[] = {-1,0,1,0};
                int dy[] = {0,1,0,-1};

                if(grid[i][j] == 0){

                    int curr = 1 ; // 0 to 1
                    set<int> st ;
                    for(int k=0; k<4; k++){

                        int newX = dx[k] + i ;
                        int newY = dy[k] + j ;

                        if(newX >=0 && newY>=0 && newX<n && newY<n && grid[newX][newY] == 1){
                            
                            // add it to the current ans 
                            int parent = ds.findP(convert(newX,newY,n));

                            if(st.find(parent) == st.end()){
                                st.insert(parent);
                                curr += ds.size[parent];

                            }

                        }

                        ans = max(ans,curr);
                    }
                    
                }
            }
        }

        ans = max(ans,ds.size[0]); // if no 0 is converted , return the whole 
        return ans ; 
    }
};