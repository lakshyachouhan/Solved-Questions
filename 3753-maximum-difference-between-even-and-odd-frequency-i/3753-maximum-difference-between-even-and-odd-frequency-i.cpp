class Solution {
public:
    int maxDifference(string s) {
        
        int freq[26] = {0};

        for(auto ch:s){

            freq[ch - 'a']++;
        }

        int odd = -1, even = 1e9 ;
        // odd wali maximum 
        // even wali minimum

        for(int i=0; i<26; i++){

            if(freq[i] == 0)    continue ;

            if(freq[i]&1){
                odd = max(odd,freq[i]);
            }

            else even = min(even,freq[i]);
        }

        return odd - even ;
    }
};