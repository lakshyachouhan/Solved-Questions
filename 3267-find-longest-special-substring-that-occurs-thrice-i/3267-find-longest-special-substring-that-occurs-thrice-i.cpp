class Solution {
public:
    int maximumLength(string s) {
        
        unordered_map<string,int> mp ;
        int n = s.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                if(s[j] == s[j-1]){
                    string curr = s.substr(i,j-i+1);
                    mp[curr]++;
                }

                else break ;

                // if(mp[curr] >= 3)   ans = max(ans,curr.size());

            }
        }


        // count individual
        for(auto ch:s){

            string curr = "";
            curr += ch ;
            mp[curr]++;
        }   

        for(auto &[str,occ]:mp){

            int size = str.size();
            if(occ >= 3){
                cout << str << "  "  << occ << endl ;
                ans = max(ans,size);
            }

        }

        return ans ;
    }
};