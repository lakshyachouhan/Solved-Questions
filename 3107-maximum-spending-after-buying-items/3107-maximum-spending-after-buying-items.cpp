#define ll long long 

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minHeap ;
        // {ele,row,col}

        int m = values.size() , n = values[0].size();

        for(int i=0 ;i<m; i++){

            minHeap.push({values[i][n-1],i,n-1});
        }

        ll ans = 0 ;
        ll d = 1 ;
        while(!minHeap.empty()){

            auto [ele,row,col] = minHeap.top();
            minHeap.pop();

            ans += ele * d ;
            d++;

            if(col > 0){
                minHeap.push({values[row][col-1],row,col-1});
            }
        }

        return ans ;
    }
};