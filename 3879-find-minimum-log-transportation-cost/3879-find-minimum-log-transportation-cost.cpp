#define ll long long 
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        
        ll ans = 0 ;

        if(k >= n && k >= m)
            return 0LL ;

        ll maxi = max(n,m);
        ll mini = min(n,m);

        if(maxi >= k){
            ll diff = maxi - k ;
            ll other = maxi - diff ;
            ans += diff * other ;
        }

        return ans ;
    }
};