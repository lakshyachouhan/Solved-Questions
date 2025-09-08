class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1; i<=n/2; i++){

            int ele1 = i ;
            int ele2 = n - i ;
            bool f = 1 ;

            while(ele1){

                if(ele1 % 10 == 0){
                    f = 0 ;
                    break ;
                }

                ele1 /= 10 ;
            }

            while(ele2){

                if(ele2 % 10 == 0){
                    f = 0 ;
                    break ;
                }

                ele2 /= 10 ;
            }

            if(f)
                return {i,n-i};
        }

        return {0,0}; // unreachable 
    }
};