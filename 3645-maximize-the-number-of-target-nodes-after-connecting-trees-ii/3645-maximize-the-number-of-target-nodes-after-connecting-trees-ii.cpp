// class Solution {
// public:
//     int dfs(unordered_map<int,list<int>> &adj,int src,int parent,bool curr,bool req){

//         int ans = (curr == req) ? 1 : 0 ;

//         for(auto nbr:adj[src]){

//             if(parent != nbr)
//                 ans += dfs(adj,nbr,src,!curr,req);
//         }

//         return ans ;
//     }


//     vector<int> solve(vector<vector<int>>& e, bool req){

//         unordered_map<int,list<int>> adj ;
//         for(auto &i:e){
//             int u = i[0] , v = i[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         // 0/1 usse kr rhe hai odd ,even ke liye 
//         // bakki count se bhi kr skte hai , distance&1

//         // 0 -> even distance pe hai 
//         // 1 -> odd distance pe hai 

//         vector<int> ans(e.size()+1) ;
//         for(int i=0; i<=e.size(); i++){
            
//             bool curr = 0 ;
//             ans[i] = dfs(adj,i,-1,curr,req);
//         }

//         return ans ;
//     }


//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
//         vector<int> ans1 = solve(edges1,0);
//         vector<int> ans2 = solve(edges2,1); // ek edge join mein lag gyi 
//         // toh tree2 mein odd distance wali count excluding self , because self 
//         // wali is at odd distance (ek node join ki)

//         int maxi = *max_element(ans2.begin(),ans2.end());
//         // jis node ka bhi maximum hai , sabko usse hi join krenge 

//         for(auto &ele:ans1)
//             ele += maxi ;

//         return ans1 ;
//     }
// };

class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    //O(V+E)
    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent, vector<int>& mark, 
        int &zeroMarkedCount, int& oneMarkedCount) {

        if(mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for(auto &ngbr : adj[curr]) {
            if(ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0; //alternate marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size()+1; // Tree A
        int M = edges2.size()+1; // Tree B

        unordered_map<int, vector<int>> adjA = getAdj(edges1); //O(V1+E1)
        unordered_map<int, vector<int>> adjB = getAdj(edges2); //O(V2+E2)

        vector<int> markA(N, -1);
        markA[0] = 0; //mark 0th node as 0
        int zeroMarkedCountA = 0;
        int oneMarkedCountA  = 0;
        dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA); //O(V+E)


        vector<int> markB(M, -1);
        markB[0] = 0; //mark 0th node as 0
        int zeroMarkedCountB = 0;
        int oneMarkedCountB  = 0;
        dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB); //O(V+E)

        int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);

        vector<int> ans(N);
        for(int i = 0; i < N; i++) { //O(V)
            ans[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) + maxFromTree2;
        }

        return ans;

        
    }
};
