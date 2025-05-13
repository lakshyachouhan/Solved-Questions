class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

        vector<int> freq(26,0);
        int MOD = 1e9 + 7 ;
        for(auto ch:s){
            freq[ch-'a'] = (1 + (freq[ch-'a'])%MOD)%MOD ;
        }

        while(t--){

            int fz = freq[25];
            freq[25] = 0 ;
            for(int i=24; i>=0; i--){
                freq[i+1] = freq[i];
                freq[i] = 0 ;
            }

            if(fz){
                freq[0] = (fz%MOD + freq[0]%MOD)%MOD ;
                freq[1] = (fz%MOD + freq[1]%MOD)%MOD ;
            }
        }

        int ans = 0 ;
        for(int i=0; i<26; i++){
            // cout << i+'a' << " " << freq[i] << endl ;
             ans = (ans+freq[i]%MOD)%MOD ;
        }
            
        return ans ;
    }
};