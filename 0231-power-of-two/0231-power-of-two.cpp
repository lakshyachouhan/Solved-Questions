class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n == 0)
            return 0 ;
        
        // if a no. is a power of 2, then it must have only 
        // one but set : 0100000 , or 000001 or any likewise

        return (n &(n*1LL-1)) == 0 ;
    }
};