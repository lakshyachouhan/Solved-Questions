class Solution {
public:
    void setZero(int &n,int pos){

        int mask = ~ (1 << pos) ;
        n &= mask ;
    }

    int minimizeXor(int num1, int num2) {
        
        int ones = __builtin_popcount(num2);
        // cout << "one  " << ones << endl ;

        for(int i=31; i>=0; i--){
            
            bool bit = (1<<i) & num1 ;
            if(bit){

                if(ones)    ones--;
                else setZero(num1,i);
            }
        }

        for(int i=0; i<32; i++){

            bool bit = (1<<i) & num1 ;
            if(ones && bit == 0){
                num1 |= 1 << i ;
                ones--;
            }
        }

        return num1 ;
    }
};