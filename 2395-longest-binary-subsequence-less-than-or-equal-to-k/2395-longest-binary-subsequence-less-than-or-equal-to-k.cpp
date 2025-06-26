class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int zeros = count(s.begin(),s.end(),'0');

        int ones = 0 ;
        int mul = 1 ; // 2^0
        long long curr = 0 ;

        for(int i=s.size()-1; i>=0; i--){

            if(s[i] == '1'){

                if(curr + 1*mul <= k){
                    // include it
                    curr += mul ;
                    ones++;
                }

                else break ;
            }

            mul <<= 1 ;  // *= 2
            if(mul > k)
                break ;
        }

        return zeros + ones ;
    }
};