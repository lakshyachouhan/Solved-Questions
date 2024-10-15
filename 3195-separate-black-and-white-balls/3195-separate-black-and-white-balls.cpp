#define ll long long 
class Solution {
public:
    long long minimumSteps(string s) {
        
        ll ans = 0 ;
        ll ones = 0 ;

        for(auto &ch:s){

            if(ch == '1')   ones++;
            else{
                ans += ones ;
            }

        }

        return ans ;
    }
};