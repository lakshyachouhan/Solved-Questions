class Solution {
public:
    int totalMoney(int n) {
        
        int ans = 0 ;
        int monday = 1 ;
        int d = 0 ;
        while(n != 0){

            ans += (monday+d);

            if(d == 6){
                d = 0 ;
                monday++;
            }

            else d++;

            n--;
        }

        return ans ;
    }
};