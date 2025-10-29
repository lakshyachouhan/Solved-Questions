class Solution {
public:
    int smallestNumber(int n) {
        
        // Stores all 2^n - 1 
        vector<int> v = {1,3,7,15,31,63,127,255,511,1023};

        for(auto ele:v){

            if(ele >= n)
                return ele ;
        }

        return -1 ;
    }
};