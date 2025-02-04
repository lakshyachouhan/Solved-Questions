class Solution {
public:
    string findValidPair(string s) {

        string ans = "";
        for(int i=0; i<s.size()-1; i++){

            char ch1 = s[i];
            char ch2 = s[i+1];

            if(ch1 != ch2){

                int first = 0 ;
                int second = 0 ;

                for(char ele:s){

                    if(ele == ch1) first++;
                    if(ele == ch2) second++;
                 }

                if(first == ch1-'0' && second == ch2-'0'){
                    ans += ch1  ;
                    ans += ch2 ;
                    return ans ;
                }
            }
        }

        return ans ;
    }
};