class Solution {
public:
    int bitwiseComplement(int n) {
    
    if(n == 0)  return 1 ;

     int ans = 0 ;
     int i = 0 ;

     while(n > 0){

        if((n&1) == 0){ // bitwise mein priority ka dhyan , ()
            ans = ans | 1<<i ;
        }

        i++;
        n >>= 1 ;
     }   

     return ans ;
    }
};