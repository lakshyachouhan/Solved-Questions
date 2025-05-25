class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> mp ;

        for(auto &s:words){
            mp[s]++;
        }

        string odd = "";
        string aage = "";
        string back = "";

        for(int i=0; i<words.size(); i++){

            string s = words[i];
            if(mp[s] == 0)
                continue ;

            string rev = s ;
            swap(rev[0],rev[1]);

            if(rev == s){

                int t = mp[s]&1 ? mp[s]-1 : mp[s] ;
                while(t--)
                    aage += s ;

                if(mp[s]&1)
                    odd = s ;

                mp[s] = 0 ;
            }

            else if(mp[rev] != 0){

                int t = min(mp[rev],mp[s]);
                mp[rev] -= t ;
                mp[s] -= t ;

                while(t--){
                    aage += s ;
                    back += rev ;
                }
            }
        }

        string ans ;
        if(odd != "")
            ans =  aage + odd + back ;

        else ans = aage + back ;

        return ans.size() ;
    }
};