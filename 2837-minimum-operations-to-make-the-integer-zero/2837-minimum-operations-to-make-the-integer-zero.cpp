#define ll long long 

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        // num1 - t*num2 = t powers of 2 
        // Let no. of operations be t
        int t = 0 ;
        while(1){

            ll val = num1*1LL - t * 1LL * num2 ;
            ll bits = __builtin_popcountll(val);

            if(bits <= t && t <= val)
                return t ;

            // -ve , cannot be represented by any power of 2
            if(val < 0)
                return -1 ; 

            t++;
        }

        return -1 ;
    }
};