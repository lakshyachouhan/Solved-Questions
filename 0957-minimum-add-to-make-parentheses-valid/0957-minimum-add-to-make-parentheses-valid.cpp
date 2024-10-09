class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0 , close = 0 ;

        for(auto &ch:s){

            if(ch == '(') open++;
            else{

                if(open)    open-- ;
                else close++;
            }
        }

        return open + close ;
    }
};