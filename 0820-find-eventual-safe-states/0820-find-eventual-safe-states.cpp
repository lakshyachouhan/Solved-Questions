class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        unordered_map<int,list<int>> adj ;
        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){

            // create a reverse graph 
            for(auto nbr:graph[i]){
                adj[nbr].push_back(i);
                indegree[i]++;
            }

        }

        queue<int> q ;
        vector<int> ans ; 

        for(int i=0;i<n; i++){

            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto nbr:adj[front]){

                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        sort(ans.begin(),ans.end());
        return ans ;
    }
};