class Solution {
public:
    vector<int > powersOf3 ;
    void computePowers(){

        int  val = 1 ;
        powersOf3.push_back(val);

        for(int  i=0; i<15; i++){
            val *= 3 ;
            powersOf3.push_back(val);
        }
    }

    bool checkPowersOfThree(int n) {
        
        computePowers();
        
        int  s = powersOf3.size();

        int  i = s-1 ;
        while(i != -1){

            if(powersOf3[i] <= n){
                n -= powersOf3[i];
            }

            i--;
        }

        return n == 0 ;
    }
};