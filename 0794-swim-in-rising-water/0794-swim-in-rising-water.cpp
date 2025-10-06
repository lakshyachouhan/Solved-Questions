class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minHeap ; // {dist,x,y}
        dist[0][0] = 0 ;
        minHeap.push({0,0,0});

        int dx[] = {-1,0,1,0} ;
        int dy[] = {0,1,0,-1} ;

        while(!minHeap.empty()){

            auto [d,x,y] = minHeap.top();
            minHeap.pop();

            if(dist[x][y] < d)
                continue ;

            if(x == n-1 && y == n-1)
                return d ;

            for(int i=0; i<4; i++){

                int newX = x + dx[i] ;
                int newY = y + dy[i] ;

                if(newX >= 0 && newY >= 0 && newX < n && newY < n){

                    int currDist = max({d,grid[x][y],grid[newX][newY]});
                    if(currDist < dist[newX][newY]){

                        dist[newX][newY] = currDist ;
                        minHeap.push({currDist,newX,newY});
                    }
                }
            }
        }

        return n ;   // problem guarantees reachability
    }
};