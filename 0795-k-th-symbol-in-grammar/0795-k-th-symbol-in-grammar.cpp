class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1 && k == 1)
            return 0 ;

        int prevK ;
        if(k&1)
            prevK = k/2 + 1 ;

        else prevK = k/2 ;

        int prev = kthGrammar(n-1,prevK);
        // prev wala mil chuka hai , ab isse build for curr row 

        // 1 based indexing 
        if(prev == 0){

            return k&1 ? 0 : 1 ;
        }

        else{
            // prev == 1
            return k&1 ? 1 : 0 ;
        }
    }
};