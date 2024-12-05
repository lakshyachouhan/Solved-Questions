class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap ;

        minHeap.push({0,{0,0}});
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 0 ;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!minHeap.empty()){

            auto top = minHeap.top();
            minHeap.pop();

            int currDist = top.first ;
            int currX = top.second.first ;
            int currY = top.second.second ;

            if(currX == m-1 && currY == n-1)
                return currDist ;

            for(int i=0; i<4; i++){

                int newX = dx[i] + currX ;
                int newY = dy[i] + currY ;

                if(newX >= 0 && newY >= 0 && newX < m && newY < n){

                    if(currDist + grid[newX][newY] < dist[newX][newY]){
                        dist[newX][newY] = currDist + grid[newX][newY] ;
                        minHeap.push({dist[newX][newY],{newX,newY}});
                    }
                }
            }
        }

        return -1 ;
        
    }
};