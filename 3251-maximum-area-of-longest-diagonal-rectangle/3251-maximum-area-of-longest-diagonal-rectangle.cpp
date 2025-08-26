class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int ansA = 0 ;
        int ansDiagonal = -1; 

        for(auto &i:dimensions){

            int l = i[0] , w = i[1] ;
            int currD = l*l + w*w ;

            if(currD > ansDiagonal){
                ansDiagonal = currD ;
                ansA = l * w ;
            }
                

            else if(currD == ansDiagonal)
                ansA = max(ansA,l*w);
        }   

        return ansA ;
    }
};