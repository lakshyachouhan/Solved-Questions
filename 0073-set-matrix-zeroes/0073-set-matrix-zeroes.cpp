class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
 /*       set<int> row , col ;
        int m = matrix.size() , n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto ele:row){
            
            for(int col=0; col<n; col++)
                matrix[ele][col] = 0 ;
        }

        for(auto ele:col){
            
            for(int row=0; row<m; row++)
                matrix[row][ele] = 0 ;
        }

*/
      int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        for (int row = 0; row < m; row++) {

            if(matrix[row][0] == 0) 
                col0 = true;
        }

        for (int col = 0; col < n; col++) {

            if(matrix[0][col] == 0) 
                row0 = true;
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0; // 0th row ke ye col
                }
            }
        }

        for (int col = 1; col < n; col++) {

            if (matrix[0][col] == 0) {
                // mark whole column zero 

                for (int row = 0; row < m; row++)
                    matrix[row][col] = 0;
            }
        }

        for (int row = 1; row < m; row++) {

            if (matrix[row][0] == 0) {
                 // mark whole row zero 

                for (int col = 0; col < n; col++)
                    matrix[row][col] = 0;
            }
        }

        if (row0) {

            for (int col = 0; col < n; col++)
                matrix[0][col] = 0;
        }

        if (col0) {

            for (int row = 0; row < m; row++)
                matrix[row][0] = 0;
        }


        
    }
};