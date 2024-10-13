#define ll long long 
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        
        string s = to_string(n);

        ll sum = 0 ;
        for(int i=0; i<s.length(); i++){
            sum += s[i] - '0';
        }

        if(sum <= target)   return 0 ;

        int j = s.length()-1;
        while(sum >= target && j > 0){

            sum -= (s[j] - '0') ;
            s[j] = '0' ;
            j--;
        }

        if(sum >= target){
            // 0 index pr pahuch gye , phir bhi chota nhi hua 
            s[0] = '0' ;
            s = '1' + s ;
        }

        else{
            // increase the last digit which is non zero by 1 
            while(s[j] == '9' && j > 0){
                s[j] = '0';
                j--;
            }

            if(s[j] == '9'){
                s[j] = '0' ;
                s = '1' + s ;
            }   
            else s[j] = s[j] + 1 ;  
        }  

        cout << s << endl ;
        return stoll(s) - n ;

    }
};