class Solution {
public:
    string solve(int x){

        string s = to_string(x);
        sort(s.begin(),s.end());

        return s ;
    }

    bool reorderedPowerOf2(int n) {
        
        string req = solve(n);

        // Check all powers of 2 
        // in digits in sorted order 
        for(int i=0; i<31; i++){

            string powerOf2 = solve(1 << i);

            if(req == powerOf2)
                return true ;
        }

        return false ;
    }
};