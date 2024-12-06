class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1 ;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > minHeap ;
        
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> time(m,vector<int>(n,1e9));

        minHeap.push({0,{0,0}});

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!minHeap.empty()){

            auto top = minHeap.top();
            minHeap.pop();

            int currT = top.first ;
            int currX = top.second.first ;
            int currY = top.second.second ;

            if(currX == m-1 && currY == n-1)
                return currT ;

            for(int i=0; i<4; i++){

                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if(newX >= 0 && newY >= 0 && newX < m && newY < n){

                    int diff = grid[newX][newY] - currT ;
                    int newT ;

                    if(diff > 0){
                        // matlab aage piche to & fro krke 
                        // reach krna padega 

                        if(diff&1){
                            newT = grid[newX][newY] ;
                        }

                        else newT = grid[newX][newY] + 1 ;
                    }

                    else newT = currT + 1 ;

                    
                        if(newT < time[newX][newY]){
                            time[newX][newY] = newT ;
                            minHeap.push({newT,{newX,newY}});
                        }

                }
            }

        }

        return -1 ;
    }
};