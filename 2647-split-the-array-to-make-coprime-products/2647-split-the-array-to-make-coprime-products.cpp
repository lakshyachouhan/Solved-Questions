// #define ll long long 

// class Solution {
// public:
//     ll GCD(ll a,ll b){

//         while(a > 0 && b > 0){

//             if(a > b)
//                 a -= b ;

//             else b -= a ;
//         }

//         return a==0 ? b : a ;
//     }

//     int findValidSplit(vector<int>& nums) {
        
//         // Precompute the left and right product 
//         // for each index 
//         ll n = nums.size();

//         // left mein , including that value 
//         // right mein aaage ki values ka 
//         vector<ll> left(n) , right(n);
//         left[0] = nums[0] ;

//         for(ll i=1 ;i<n; i++)
//             left[i] = 1LL * left[i-1] * nums[i];

//         right[n-1] = 1 ;
//         for(ll i=n-2; i>=0; i--)
//             right[i] = right[i+1] * nums[i+1];

//         ll ans = 0 ;
//         for(ll i=0; i<n-1; i++){

//             // cout << i << "  " << left[i] << "  "<< right[i] << " " << GCD(left[i],right[i]) << endl ;
//             if(GCD(left[i],right[i]) == 1)
//                 return i ;
//         }

//         return -1 ;
//     }
// };

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> lastIndex; 
        // prime -> last index where it appears

        auto getPrimes = [](int x) {

            unordered_set<int> primes;
            for (int d = 2; d * d <= x; ++d) {
                while (x % d == 0) {
                    primes.insert(d);
                    x /= d;
                }
            }

            if (x > 1) primes.insert(x);
            return primes;
        };

        for (int i = 0; i < n; ++i) {
            
            for (int p : getPrimes(nums[i])) {
                lastIndex[p] = i;
            }
        }

        
        int maxRight = 0; // last index of any prime 
        for (int i = 0; i < n - 1; ++i) {

            for (int p : getPrimes(nums[i])) {
                maxRight = max(maxRight, lastIndex[p]);
            }

            if (i == maxRight) 
                return i; 
        }

        return -1;
    }
};
