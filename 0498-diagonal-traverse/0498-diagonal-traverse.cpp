class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size() , n = mat[0].size();
        vector<int> ans ;

        for(int i=0; i<m; i++){
            
            int row = i ;
            int j = 0 ;
            vector<int> curr ;
            while(row >= 0 && j<n){
                curr.push_back(mat[row][j]);
                row -= 1;
                j += 1 ;
            }

            // col fixed , all starting from 0th col
            if((i+0)&1)
                reverse(curr.begin(),curr.end());

            ans.insert(ans.end(),curr.begin(),curr.end());
        }

        for(int j=1; j<n; j++){

            int row = m-1 ;
            int col = j ;
            vector<int> curr ;
            while(row >= 0 && col<n){
                curr.push_back(mat[row][col]);
                row -= 1;
                col += 1 ;
            }

            // row fixed , i.e last row
            if(((m-1)+j)&1)
                reverse(curr.begin(),curr.end());

            ans.insert(ans.end(),curr.begin(),curr.end());
        }

        return ans ;
    }
};