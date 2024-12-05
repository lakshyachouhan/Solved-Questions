class Solution {
public:
    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5},
                               {0, 4}, {3, 5, 1}, {4, 2}};

    
    int slidingPuzzle(vector<vector<int>>& b) {

        string s;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += to_string(b[i][j]);
            }
        }
        
        unordered_map<string, bool> vis;
        queue<pair<string,int>> q ;
        q.push({s,0});
        vis[s] = 1 ;
        
        while(!q.empty()){

            auto [curr,steps] = q.front();
            q.pop();

            if(curr == "123450")    return steps ;

            int index = curr.find('0');

            for(auto i:dir[index]){
                swap(curr[i],curr[index]);
                    if(!vis[curr]){
                            q.push({curr,steps+1});
                            vis[curr] = 1; 
                    } 
                        
                swap(curr[i],curr[index]);
            }
        }

        return -1;
    }
};
