class Solution {
public:
    int findComplement(int num) {
        
        int ans = 0 ;
        int i= 0 ;

        while(num){

            bool curr = 1 & num ;
            if(curr == 0){
                
                 ans = (1<<i) | ans ;
            }

            num >>= 1 ;
            i++;
        }

        return ans ;
    }
};