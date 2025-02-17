class Solution {
public:
    // int ans = 0 ;
    // void solve(vector<int> &freq,int n,int len){

    //     if(len == n)
    //         return ;

        
    //     for(int i=0; i<26; i++){
            
    //         if(freq[i]){

    //             freq[i]--;
    //             ans++;
    //             solve(freq,n,len+1);

    //             // backtrack
    //             freq[i]++;
    //         }
    //     }

    // }


    int solve(vector<int> &freq,int n,int len){

        if(len == n)
            return 0 ;

        int ans = 0 ;
        for(int i=0; i<26; i++){
            
            if(freq[i]){

                freq[i]--;
                ans++;
                ans += solve(freq,n,len+1);

                // backtrack
                freq[i]++;
            }
        }

        return ans ;
    }


    int numTilePossibilities(string tiles) {
        
        vector<int> freq(26,0) ;
        for(auto &ch:tiles)
            freq[ch-'A']++;

        int n = tiles.size();
        int ans = solve(freq,n,0);
        return ans ;
    }
};