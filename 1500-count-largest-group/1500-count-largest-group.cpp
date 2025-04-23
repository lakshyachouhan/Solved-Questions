class Solution {
public:
    int countLargestGroup(int n) {

        unordered_map<int,int > mp1 ;

        for(int i=1; i<=n; i++){

            int sum = 0 ;
            int temp = i ;
            while(temp){

                sum += temp%10 ;
                temp /= 10 ;
            }

            mp1[sum]++;
        }

        map<int,int> mp2 ; // sorted 

        for(auto [sum,freq]:mp1){

            cout << sum << "  " << freq << endl ;
            mp2[freq]++;
        }

        return mp2.rbegin()->second ;        
    }
};