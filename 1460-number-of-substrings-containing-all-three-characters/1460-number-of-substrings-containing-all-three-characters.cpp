class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int ans = 0 ;
        unordered_map<char,int> mp ;
        int n = s.size();

        int i = 0 ;
        int j = 0 ;
        while(j < n){

            mp[s[j]]++;

            while(mp.size() == 3){
                // aage ke bhi jitne hai poore add
                ans += n-j ;

                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);

                i++;
            }

            j++;
        }
        
        return ans ;
    }
};