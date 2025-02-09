class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size() ;
        vector<vector<int>> bottomLeft(n) ; // decreasing
        vector<vector<int>> topRight(n) ; // increasing 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                int num = i-j ;
                if(num >= 0)  bottomLeft[num].push_back(grid[i][j]);

                else topRight[-num].push_back(grid[i][j]);
            }
        }

        for(int i=0; i<n; i++){

            sort(bottomLeft[i].begin(),bottomLeft[i].end());
            sort(topRight[i].rbegin(),topRight[i].rend());

            // values ko last se access krenge inme
            // isliye ulte order mein sort  
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                int num = i-j ;
                if(num >= 0){
                    // bottomLeft
                    grid[i][j] = bottomLeft[num].back();
                    bottomLeft[num].pop_back();
                }  

                else{
                     num = - num ;
                     grid[i][j] = topRight[num].back();
                     topRight[num].pop_back();
                } 
            }
        }

        return grid ;        
    }
};