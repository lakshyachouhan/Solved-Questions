// #define ll long long 

// class Solution {
// public:
//     long long minOperations(vector<vector<int>>& queries) {
        
//         ll ans = 0 ;
//         for(auto v : queries){

//             int l = v[0] , r = v[1] ;

//                 int curr = 0 ;
//                 for(int i=l ;i<=r; i++){

//                     int temp = i ;
//                     while(temp){
//                         temp = floor(temp/4);
//                         curr++;
//                     }
//                 }

//                 ans += curr/2 ;
//                 if(curr%2 != 0)
//                     ans += 1 ;
//         }

//         return ans ;
//     }
// };

#define ll long long
class Solution {
public:
    // Calculate operations for 1 to x 
    ll calc(ll x) {

        if (x == 0) 
            return 0;

        ll ans = 0 ;
        ll p = 1, currOp = 1;

        while (p <= x) {
        // check between powers of 4 
            ll next = min(x, p * 4 - 1);
            ans += (next - p + 1) * currOp;
            p *= 4;
            currOp++;
        }

        return ans;
    }

    long long minOperations(vector<vector<int>>& q) {

        ll ans = 0;

        for (auto &v : q) {
            ll l = v[0], r = v[1];
            
            ll curr = calc(r) - calc(l - 1);
            ans += (curr + 1) / 2; // ceil(curr/2)
        }
        
        return ans;
    }
};
