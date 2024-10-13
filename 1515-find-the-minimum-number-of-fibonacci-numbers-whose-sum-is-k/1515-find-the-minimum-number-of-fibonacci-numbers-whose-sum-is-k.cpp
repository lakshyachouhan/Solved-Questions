class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        vector<int> v ;
        v.push_back(1);
        v.push_back(1);

        int a = 1 , b = 1 ;
        int c = 0 ;
        while(c <= k){
            c = a+b ;
            a = b ;
            b = c ;
            v.push_back(c);
        }

        int ans = 0 ;
        while(k != 0){

            auto it = upper_bound(v.begin(),v.end(),k);
            it-- ;
            ans += k/(*it) ;
            k = k%(*it);
        }

        return ans ;
    }
};