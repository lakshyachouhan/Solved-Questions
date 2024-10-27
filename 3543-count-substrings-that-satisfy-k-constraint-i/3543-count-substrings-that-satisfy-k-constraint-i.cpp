class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        int ans = 0 ;
        for(int i=0; i<s.length(); i++){
            int o = 0 , z = 0 ;
            for(int j=i; j<s.length(); j++){

                if(s[j] == '0') z++;
                else o++;

                if(z <= k || o <= k)    ans++;

            }
        }

        return ans; 
    }
};