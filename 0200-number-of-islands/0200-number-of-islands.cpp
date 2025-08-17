class Solution {
public:
    void dfs(vector<vector<char>>& grid,int sr,int sc,map<pair<int, int>, bool>& vis){

        vis[{sr,sc}] = true ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++){

            int newX = dx[i] + sr ;
            int newY = dy[i] + sc ;

            if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && !vis[{newX,newY}]
                      && grid[newX][newY] == '1')
                      dfs(grid,newX,newY,vis); 
        }

    }



    int numIslands(vector<vector<char>>& grid) {

        int ans = 0;
        map<pair<int, int>, bool> vis;  // { {i,j} ,T/F }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(!vis[{i,j}] && grid[i][j] == '1'){
                    dfs(grid,i,j,vis);
                    ans += 1 ;
                }
            }
        }


        return ans ;
    }
};