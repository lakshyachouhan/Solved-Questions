class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        if(k == 1)
            return 'a' ;

        int n = operations.size() ; // max itni baar 
        long long len = 1 ;
        long long newK = -1 ;
        int newOp = -1 ;

        for(int i=0; i<n; i++){

            len *= 2 ;

            if(len >= k){
                newK = k - len/2 ;
                newOp = operations[i];
                break ;
            }
        }

        char ans = kthCharacter(newK,operations);

        if(newOp == 0)
            return ans ;

        return ans == 'z' ? 'a' : ans+1 ; 
    }
};