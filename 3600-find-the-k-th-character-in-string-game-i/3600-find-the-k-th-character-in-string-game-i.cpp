class Solution {
public:
    char kthCharacter(int k) {
        
        string ans = "a";

        while(ans.size() < k){

            string temp = "";

            for(auto ch:ans){

                temp += ((ch-'a' + 1)%26 + 'a' ) ;
            }

            ans += temp ;
        }


        // cout << ans << endl ;
        return ans[k-1];
    }
};