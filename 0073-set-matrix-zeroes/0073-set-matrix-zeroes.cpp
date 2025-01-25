class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> row , col ;
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

    }
};