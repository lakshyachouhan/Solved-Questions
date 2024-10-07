class Solution {
public:
    int minLength(string s) {
        
        // bool changes = true ;
        // while(changes){

        //     changes = 0 ;

        //     if(s.find("AB") != string::npos){
        //         s.erase(s.find("AB"),2);
        //         changes = 1 ;
        //     }

        //     if(s.find("CD") != string::npos){
        //         s.erase(s.find("CD"),2);
        //         changes = 1 ;
        //     }
        // }

        // return s.size() ;

        int i = -1 , j  = 0 ;
        while(j < s.length()){
            i++;
            s[i] = s[j];
            j++;

            if(i >= 1 && ((s[i] == 'B' && s[i-1] == 'A') || (s[i-1] == 'C' && s[i] == 'D')) ) 
                        i -= 2 ;
        }

        return i+1 ; // length
    }
};