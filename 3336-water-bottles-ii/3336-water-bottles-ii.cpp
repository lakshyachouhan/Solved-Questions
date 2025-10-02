class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int curr = numBottles ;
        int empty = 0 ;
        int ans = 0 ;

        while(curr != 0){

            ans += curr ;
            empty += curr ;
            curr = 0 ;

            while(empty >= numExchange){

                curr += 1 ;
                empty -= numExchange ;
                numExchange++;
            }
        }   

        return ans ;
    }
};