class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int top = n , bottom = 0 , left = m , right = 0 ;

        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 1){

                    top = min(top,i);
                    bottom = max(bottom,i);
                    left = min(left,j);
                    right = max(right,j);
                }
            }
        }

        int ans = (bottom-top+1) * (right-left+1);
        return ans ;
    }
};