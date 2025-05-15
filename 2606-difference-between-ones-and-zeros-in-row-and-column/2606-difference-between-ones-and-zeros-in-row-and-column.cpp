class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        unordered_map<int,int> row,col ; // zeros ka count 
        // ones ka count = total - zeros 

        int m = grid.size() , n = grid[0].size();

        for(int i=0; i<m; i++){
            
            int z = 0 ;
            for(int j=0; j<n; j++){

                if(grid[i][j] == 0)
                    z++;
            }

            row[i] = z ;
        }

        for(int i=0; i<n; i++){
            
            int z = 0 ;
            for(int j=0; j<m; j++){

                if(grid[j][i] == 0)
                    z++;
            }

            col[i] = z ;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                int ans = (m-row[i]) + (n-col[j]) - row[i] - col[j] ;
                grid[i][j] = ans ;
            }
        }

        return grid ;
    }
};