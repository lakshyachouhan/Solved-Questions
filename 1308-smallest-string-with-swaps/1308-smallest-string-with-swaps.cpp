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


    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        unordered_map<int,list<int>> adj ;
        for(auto i:pairs){

            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n = s.size();
        vector<bool> vis(n,0);

        vector<vector<int>> grouped ; // grouped indexes
        for(int i=0; i<n; i++){

            if(!vis[i]){
                vector<int> temp ;
                dfs(adj,i,vis,temp);
                sort(temp.begin(),temp.end());
                grouped.push_back(temp);
            }
        }

        for(auto v:grouped){

            vector<char> vChars ;
            for(int i=0; i<v.size(); i++){
                vChars.push_back(s[v[i]]);
                // cout << v[i] << "  " ;
            }
                

            sort(vChars.begin(),vChars.end());

            for(int i=0; i<v.size(); i++)
                s[v[i]] = vChars[i];

            cout << endl ;
        }

        return s ;
    }
};