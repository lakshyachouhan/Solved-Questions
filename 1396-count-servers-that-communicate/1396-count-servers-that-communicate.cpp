class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int ans = 0 ;
        int m = grid.size() , n = grid[0].size() ;

        vector<int> row(m,0) , col(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 1){
                    
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 1){
                    
                    if(row[i] > 1 || col[j] > 1)    // matlab communicate krrha hai 
                        ans++;
                }
            }
        }

        return ans ;
    }
};