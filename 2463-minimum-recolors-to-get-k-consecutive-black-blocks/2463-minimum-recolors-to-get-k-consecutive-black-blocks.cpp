class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int ans = 1e9 ;

        for(int i=0; i<=blocks.size()-k; i++){

            int w = 0 ;
            for(int j=i; j<i+k; j++){
                if(blocks[j] == 'W')    w++;
            }

            ans = min(ans,w);
        }

        return ans ;
    }
};