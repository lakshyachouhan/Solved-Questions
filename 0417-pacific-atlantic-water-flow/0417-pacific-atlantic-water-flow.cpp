class Solution {
public:
    void dfs(int srcX,int srcY,vector<vector<int>>& heights,
    vector<vector<bool>>& vis){

        int m = heights.size() , n = heights[0].size(); 
        vis[srcX][srcY] = 1 ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++){

            int newX = dx[i] + srcX ;
            int newY = dy[i] + srcY ;

            if(newX < m && newY < n && newX >= 0 && newY >= 0 && heights[newX][newY] >= heights[srcX][srcY] && !vis[newX][newY]){

                dfs(newX,newY,heights,vis);
            }
        }


    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        // Always 
        // Pacific  -> first row , first col 
        // Atlantic -> last row , last col 

        // ab inse bakki check 
        // agr greater toh jaa skte hai 

        int m = heights.size() , n = heights[0].size(); 

        vector<vector<bool>> pacific(m,vector<bool>(n,0));
        vector<vector<bool>> atlantic(m,vector<bool>(n,0));

        for(int i=0; i<n; i++){

            dfs(0,i,heights,pacific); // first row 
            dfs(m-1,i,heights,atlantic); // last row 
        }

        for(int i=0; i<m; i++){

            dfs(i,0,heights,pacific); 
            dfs(i,n-1,heights,atlantic); 
        }

        vector<vector<int>> ans ;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans ;
    }
};