class Solution {
public:
    string removeDigit(string number, char digit) {
        
        string ans ; 
        // long long ansN = -1 ;
        int pos = 0 ;

        while(number.find(digit,pos) != -1){

            int i = number.find(digit,pos) ;
            pos = i+1 ;
            string temp = number.substr(0,i) + number.substr(i+1) ;
            if(ans.empty() || ans < temp){
                ans = temp ;
            }
        }

        return ans ;

    }
};