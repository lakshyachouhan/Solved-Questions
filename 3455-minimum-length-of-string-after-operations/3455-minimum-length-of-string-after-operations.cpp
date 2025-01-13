class Solution {
public:
    int minimumLength(string s) {
        
        int ans = 0 ;
        unordered_map<char,int> freq ;

        for(auto ch:s){
            freq[ch]++;
        }

        for(auto [ch,occ]:freq){

            if(occ & 1)    ans += 1 ;
            else ans += 2 ;
        }

        return ans ;
    }
};