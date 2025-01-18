class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        // saari nodes 0 tak pahuchna chaiye 
        // ya reverse ke baad 0 se saari nodes tak pahuchna chaiye

        // APPROACH 1 -> B.S (min of max or max of min)
        // s = 0 , e = highest value , ab hr baar check
        // PREDICATE FN -> agr mid weight se kaam wali nodes le toh kya saari nodes visit krna possible hai (BFS from 0)

        // APPROACH 2 -> PRIMS ALGO 

        unordered_map<int,list<pair<int,int>>> adj ;

        for(auto i:edges){

            int u = i[0],v = i[1] , w = i[2];

            adj[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > minHeap;
        
        unordered_map<int,bool> vis; 
        minHeap.push({0,0});

        int ans = -1 ;
        while(!minHeap.empty()){

            auto [w,node] = minHeap.top();
            minHeap.pop();

            if(!vis[node]){

                vis[node] = 1 ;
                ans = max(ans,w);

                for(auto nbr:adj[node]){

                    int nbrNode = nbr.first , dist = nbr.second ;
                    if(!vis[nbrNode])
                        minHeap.push({dist,nbrNode});
                }
            }
        }

        for(int i=0; i<n; i++){

            if(!vis[i])
                return -1 ;
        }

        return ans ;
    }
};