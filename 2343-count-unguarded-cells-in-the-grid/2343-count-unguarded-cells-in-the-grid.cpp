class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> mat(m,vector<int>(n,0));
        // 0 unvisited ,jo ki ans 
        // 2 wall
        // 3 guard 
        // 1 under guard

        for(auto i:walls){
            mat[i[0]][i[1]] = 2 ;
        }

        for(auto i:guards){
            mat[i[0]][i[1]] = 3 ;
        }

        for(auto v:guards){

            int x = v[0] , y = v[1];
            for(int j=y-1; j>=0; j--){
                if(mat[x][j] == 2 || mat[x][j] == 3)  break ;
                else mat[x][j] = 1 ;
            }

            for(int i=x-1; i>=0; i--){
                if(mat[i][y] == 2 || mat[i][y] == 3)  break ;
                else mat[i][y] = 1 ;
            }

            for(int j=y+1; j<n; j++){
                if(mat[x][j] == 2 || mat[x][j] == 3)  break ;
                else mat[x][j] = 1 ;
            }

            for(int i=x+1; i<m; i++){
                if(mat[i][y] == 2 || mat[i][y] == 3)   break ;
                else mat[i][y] = 1 ;
            }

            mat[x][y] = 3 ;
        }

        int ans = 0 ;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(mat[i][j] == 0)
                    ans++;
            }
        }

        return ans ;
    }
};