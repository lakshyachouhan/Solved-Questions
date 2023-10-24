class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int row_s = 0 , col_s = 0;
        int row_e = matrix.size()-1 ;
        int col_e = matrix[0].size()-1;

        while(row_s <= row_e && col_s <= col_e){

            for(int col = col_s; col<= col_e; col++)
               ans.push_back(matrix[row_s][col]);

            row_s++;

            for(int row = row_s; row<=row_e; row++){
                ans.push_back(matrix[row][col_e]);
            }
            col_e--;
            
            if(row_s > row_e )  break ;

            for(int col = col_e; col >= col_s; col--)
               ans.push_back(matrix[row_e][col]);

            row_e--;

            if(col_s > col_e )  break ;
            for(int row = row_e; row>=row_s; row--){
                ans.push_back(matrix[row][col_s]);
            }
            col_s++;
        }

        return ans ;
    }
};