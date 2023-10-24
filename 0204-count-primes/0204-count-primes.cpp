class Solution {
public:
    // bool isPrime (int n ){
    //     for(int i=2; i<(n); i++){
            
    //         if(n%i == 0)
    //            return false ;
    //     }
    //     return true ;
    // }


    int countPrimes(int n) {
        // int count = 0 ;
        // for(int i=2; i<n; i++){
           
        //     if(isPrime(i))
        //         count++ ;
        // }

        // return count ;
        int count = 0;
        vector<int> v(n,0);
        for(int i=2; i<n; i++){
            if(v[i] == 0)
            {   count++;
                for(int j=2*i; j<n; j+=i)
                    v[j] = 1;
            }
        }

        // for(int i=2; i<n; i++){
        //     if(v[i] == 0)
        //        count++;
        // }

        return count ;


    }
};