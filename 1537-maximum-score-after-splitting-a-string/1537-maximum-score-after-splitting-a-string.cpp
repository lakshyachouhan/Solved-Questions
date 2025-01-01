class Solution {
public:
    int maxScore(string s) {
        
        int ones = count(s.begin(),s.end(),'1');

        int zero = 0 ;
        int ans = -1 ;

        for(int i=0; i<s.size()-1; i++){
                
            char ch = s[i];
            if(ch == '0')   zero++;
            else ones--;

            int curr = zero + ones ;
            ans = max(ans,curr);
        }

        return ans ;
    }
};