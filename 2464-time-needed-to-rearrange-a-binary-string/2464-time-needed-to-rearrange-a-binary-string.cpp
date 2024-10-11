class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int ans = 0 ;
        bool found = true ;

        while(found){

            found = 0 ;
            ans++;
            for(int i=0; i<s.size()-1; i++){

                if(s[i] == '0' && s[i+1] == '1'){

                    s[i] = '1';
                    s[i+1] = '0';
                    i++;
                    found = true ;
                }
            }

            // cout << s << endl ;
        }

        return ans == 1 ? 0 : --ans ;
    }
};