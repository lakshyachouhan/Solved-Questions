class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=m-2; i>=0; i--){

            for(int j=n-2; j>=0; j--){

                if(matrix[i][j] != 0){
                     int mini = min({matrix[i][j+1],matrix[i+1][j],matrix[i+1][j+1]});
                     matrix[i][j] += mini ;
                }

            }
        }
        
        int ans = 0 ;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                ans += matrix[i][j];
        }

        return ans ;
    }
};