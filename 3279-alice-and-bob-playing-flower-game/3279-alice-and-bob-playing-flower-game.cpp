#define ll long long 

class Solution {
public:
    long long flowerGame(int n, int m) {
        
        // Alice will only win when sum of all flowers from both lanes
        // are odd 
        //so check pairs from both lane , whose sum adds up to odd 

        ll ans = 0 ;
        int even = m/2 ;
        int odd = m - even ;

        for(int i=1; i<=n; i++){

            if(i&1){
                // even value chaiye from lane 2  
                ans += even ;
            }

            else ans += odd ;
        }

        return ans ;
    }
};