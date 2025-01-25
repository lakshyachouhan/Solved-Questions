class Solution {
public:
        void dfs(unordered_map<int,list<int>> &adj,int i,vector<bool>& vis,vector<int> & temp){

        // cout << i << endl ;
        temp.push_back(i);
        vis[i] = 1 ;

        for(auto nbr:adj[i]){

            if(!vis[nbr])
                 dfs(adj,nbr,vis,temp);
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        if(allowedSwaps.empty()){

            int ans = 0 ;
            for(int i=0; i<source.size(); i++)
                ans += source[i] != target[i];

            return ans ;
        }

        unordered_map<int,list<int>> adj ;  // graph of indexes 
        for(auto i:allowedSwaps){

            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n = source.size();
        vector<bool> vis(n,0);

        vector<vector<int>> grouped ; // grouped indexes
        for(int i=0; i<n; i++){

            if(!vis[i]){
                vector<int> temp ;
                dfs(adj,i,vis,temp);
                grouped.push_back(temp);
            }
        }

        int ans = 0 ;
        for(auto v:grouped){
                
            unordered_map<int,int> freq ;
            for(auto i:v){
                freq[target[i]]++;
            }

            for(auto i:v){
                
                int ele = source[i];
                if(freq.count(ele)){
                    freq[ele]--;
                    if(freq[ele] == 0)  
                        freq.erase(ele);
                }

                else ans++;
            }
            
        }

        return ans ;
    }
};