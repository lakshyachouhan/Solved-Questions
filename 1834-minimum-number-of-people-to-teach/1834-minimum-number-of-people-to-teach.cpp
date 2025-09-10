class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        // que. descriptive toh hai , samajhne mein 
        // approach banane mein time to lagega 
        // 1.Remove pairs that can communicate from friendship
        // 2.For those who cannot , increase the freq. of languges
        // and teach the max. freq lang to others 
        // since we can select and teach only one language 

        unordered_map<int,int> freq ;
        map<int,set<int>> userLanguage ; // for ease in checking
        unordered_map<int,bool> vis ;

        for(int i=0; i<languages.size(); i++){

            auto &v = languages[i];
            userLanguage[i+1] = set<int>(v.begin(),v.end());
        }

        for(auto f:friendships){

            int p1 = f[0] , p2 = f[1];
            bool canCommunicate = 0 ;

            for(auto lan:userLanguage[p1]){

                if(userLanguage[p2].find(lan) != userLanguage[p2].end()){
                    canCommunicate = 1 ;
                    break ;
                }
            }

            if(canCommunicate == 0){

                // increase freq. of languages known to both users
                if(!vis[p1]){
                    vis[p1] = 1 ;

                    for(auto lan:userLanguage[p1])
                        freq[lan]++;                
                }

                if(!vis[p2]){
                    vis[p2] = 1 ;

                    for(auto lan:userLanguage[p2])
                        freq[lan]++;                
                }
            }
        }

        int maxi = 0 ;
        for(auto [l,f]:freq){

            maxi = max(maxi,f);
        }

        return vis.size() - maxi ;
    }
};