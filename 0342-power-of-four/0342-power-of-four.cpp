class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n < 0)
            return 0 ;

        double k = n ;
        while(k >= 4){

            k /= 4.0 ;
        }

        return k == 1.0 ;         
    }
};