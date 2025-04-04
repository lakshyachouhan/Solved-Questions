class Solution {
public:
/*
Pattern Tpye : 
        "answer based on previous answers" optimization:

Find answer for 1st 
Find answer for 2 (which includes 1)
Find answer for 3 (which includes 1+2)
*/ 


    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();


        vector<pair<int,int>> sortedQ ; // {ele,index}
        for(int i=0; i<queries.size(); i++){
            sortedQ.push_back({queries[i],i});
        }

        sort(sortedQ.begin(),sortedQ.end());

        vector<int> ans(queries.size());
        int points = 0 ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > minHeap ; // {ele,{i,j}}

        minHeap.push({grid[0][0],{0,0}});

        vector<vector<bool>> vis(m,vector<bool>(n,0));
        vis[0][0] = 1 ;

        int dx[] = {-1,0,1,0}; 
        int dy[] = {0,1,0,-1};

        for(int i=0; i<queries.size(); i++){

            int val = sortedQ[i].first ;
            int idx = sortedQ[i].second ;

            // visit all smalller value cells 
            while(!minHeap.empty() && minHeap.top().first < val){

                auto top = minHeap.top();
                int x = top.second.first ;
                int y = top.second.second ;
                minHeap.pop();

                points++;

                for(int i=0; i<4; i++){

                    int newX = dx[i] + x ;
                    int newY = dy[i] + y ;

                    if(newX>=0 && newY>=0 && newX < m && newY <n){

                        if(!vis[newX][newY]){
                            vis[newX][newY] = 1 ;
                            minHeap.push({grid[newX][newY],{newX,newY}});
                        }
                    }
                }
            }

            ans[idx] = points; 
        }

        return ans ;        
    }
};