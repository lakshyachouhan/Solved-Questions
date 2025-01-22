class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        // Pehle Topic Identify -> Multi Source Bfs

        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // -1 -> unvisited
        queue<pair<int,int>> q;
        
       
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
                
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;
                
                if(newX >= 0 && newY >= 0 && newX < m && newY < n && ans[newX][newY] == -1) {
                    ans[newX][newY] = ans[x][y] + 1;
                    q.push({newX,newY});
                }
            }
        }
        
        return ans;
    }
};