class Solution {
public:
    int minMaxDifference(int num) {
        
        string s = to_string(num);

        char firstD = s[0] ;
        string maxi = "" , mini = "" ;

        char firstDNot9 = '9';
        for(auto ch:s){

            if(ch != '9'){
                firstDNot9 = ch ;
                break ;
            }
        }

        for(auto ch:s){

            if(ch == firstD){
                mini += '0';
            }

            else{
                mini += ch ;
            }

            if(ch == firstDNot9){
                maxi += '9';
            }

            else{
                maxi += ch ;
            }

        }

        long long ans = stoll(maxi) - stoll(mini);
        return ans ;
    }
};