class Solution {
public:
    int maxDiff(int num) {
        
        string s = to_string(num);

        char firstD = '9' ; // for the maximum
        for(auto ch:s){

            if(ch != '9'){
                firstD = ch ;
                break ;
            }
        }

        string maxi = "";
        for(auto ch:s){

            if(ch == firstD){
                maxi += '9';
            }

            else maxi += ch ;
        }

        // for minumum , replace it with 0 or 1 
        // lekin leading 0's not allowed 
        // toh first digit > 1 , toh replace by 1
        // else if == 1 , toh first non-one , non-zero ko replace

        string mini = "" ;

        if(s[0] > '1'){
            
                for(auto ch:s){

                if(ch == s[0])
                    mini += '1' ;

                else mini += ch ;
            }

        }

        else{

            char replaceD = '1';
             for(auto ch:s){

                if(ch != '0' && ch != '1' && replaceD == '1'){
                    // finded the digit whcih needs to be replaced
                    replaceD = ch ;
                    mini += '0' ;
                }
                    
                else if(replaceD != '1' && ch == replaceD)
                    mini += '0';

                else mini += ch ;
            }
        }
        
        cout << maxi << "   "<< mini << endl ;
        int ans = stoi(maxi) - stoi(mini);
        return ans ;

    }
};