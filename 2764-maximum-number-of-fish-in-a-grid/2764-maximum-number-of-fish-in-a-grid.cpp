class Solution {
public:
    int dfs(vector<vector<int>>& grid,int srcX,int srcY,map<pair<int,int>,bool> &vis){
        int m = grid.size() ;
        int n = grid[0].size();
        int ans = grid[srcX][srcY];
        vis[{srcX,srcY}] = 1 ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++){

            int newX = srcX + dx[i] ;
            int newY = srcY + dy[i] ;

            if(newX >= 0 && newY>=0 && newX <m && newY<n){

                if(grid[newX][newY] > 0 && !vis[{newX,newY}])
                    ans += dfs(grid,newX,newY,vis);
            }
        }

        return ans ;
    }


    int findMaxFish(vector<vector<int>>& grid) {
        
        map<pair<int,int>,bool> vis ;
        int ans = 0 ;

        for(int i=0; i<grid.size();i++){

            for(int j=0; j<grid[0].size(); j++){

                if(grid[i][j] > 0 && !vis[{i,j}]){
                    int curr = dfs(grid,i,j,vis);
                    ans = max(ans,curr);
                }
            }
        }

        return ans ;
    }
};