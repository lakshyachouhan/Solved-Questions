class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size() ;
        if(m == 1 && n == 1)
            return 0 ;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > minHeap ;
        minHeap.push({0,{0,0}});

        vector<vector<int>> dist(m,vector<int>(n,1e9));

        int dx[] = {0,0,1,-1} ;
        int dy[] = {1,-1,0,0} ;

        while(!minHeap.empty()){

            auto top = minHeap.top();
            minHeap.pop();

            int currDist = top.first , currX = top.second.first ;
            int currY = top.second.second;

            if(currDist > dist[currX][currY])
                continue ;

            for(int i=0; i<4; i++){
                
                // agr same dir toh change nhi krna agr different 
                // toh +1 
                int cost = grid[currX][currY]-1 == i ? 0 : 1 ;
                int newX = dx[i] + currX ;
                int newY = dy[i] + currY ;

                if(newX >= 0 && newY >= 0 && newX < m && newY < n){

                    if(cost + currDist < dist[newX][newY]){
                        dist[newX][newY] = cost + currDist ;
                        minHeap.push({dist[newX][newY],{newX,newY}});
                    }
                }
                
            }

        }

        return dist[m-1][n-1];
        
    }
};