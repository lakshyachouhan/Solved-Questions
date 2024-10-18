class Solution {
public:
    bool dfs(int srcX,int srcY,vector<vector<int>>& grid2,map<pair<int,int>,bool> &vis,set<pair<int,int>> &st){

        vis[{srcX,srcY}] = true ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        bool ans = true ;

        for(int i=0; i<4; i++){

            int newX = dx[i] + srcX ;
            int newY = dy[i] + srcY ;
            if(newX >=0 && newY >=0 && newX < grid2.size() && newY < grid2[0].size() ){

                if(!vis[{newX,newY}] && grid2[newX][newY] == 1){
                    if(st.find({newX,newY}) != st.end()){
                        if(dfs(newX,newY,grid2,vis,st) == false){
                            ans = false ;
                        }
                    }

                    else ans = false ;
                }
            }
        }

        return ans ;
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        set<pair<int,int>> st ;
        int m = grid1.size();
        int n = grid1[0].size() ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid1[i][j] == 1)
                    st.insert({i,j});
            }
        }

        int ans = 0 ;
        map<pair<int,int>,bool> vis ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid2[i][j] == 1 && !vis[{i,j}] && st.find({i,j}) != st.end()){

                    if(dfs(i,j,grid2,vis,st) == true ){
                        ans++;
                        cout << i << " " << j << endl ;
                    }
                }
            }
        }

        return ans ;
    }
};