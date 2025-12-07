class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low == high && low&1)
            return 1 ;

        int val = high-low-1 ;

        // both odd
        if(low&1 && high&1)
            return val/2 + 2 ;

        // both even
        else if(!(low&1) && !(high&1))
            return (val+1)/2 ;

        else return val/2 + 1 ;
    }
};