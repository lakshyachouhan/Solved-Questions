class Solution {
public:
    string largestGoodInteger(string s) {
        
        int ans = -1 ; // only storing the digit 
        // which can make the answer 

        for(int i=2; i<s.size(); i++){

            if(s[i-2] == s[i] && s[i-1] == s[i]){

                int digit = s[i] - '0' ;
                ans = max(ans,digit);
            }
        }


        if(ans != -1){
            
            // string(len,char)
            string finalAns = string(3,ans+'0');
            return finalAns ;
        }

        return "";
    }
};