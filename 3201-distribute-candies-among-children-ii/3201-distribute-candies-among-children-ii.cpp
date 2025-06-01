#define ll long long 

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        ll ans = 0 ;

        for(int i=0; i<=min(limit,n); i++){

            if(n-i > 2*limit)
                continue ;

            // i candies given to B
            // A + C =  N - B
            // ab ek kisi ki bhi uppr limit and lower limit se ans find
            // max(0,(n−B)−limit) ≤  A  ≤ min(limit,(n−B))
            ans += min(limit,n-i) - max(0,n-i-limit) + 1 ;
        }

        return ans ;
    }
};