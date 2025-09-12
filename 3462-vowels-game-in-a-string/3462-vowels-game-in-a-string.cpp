class Solution {
public:
    bool doesAliceWin(string s) {
        
        // Alice bas starting mein haar skta hai 
        // jab vowels count = 0
        // if vowels even -> toh odd select , odd remains
        // if vowels odd -> toh all select 
        
        for(int i=0; i<s.length(); i++){

            char ch = s[i] ;
            if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i')
                return true ;
        }

        return false ;
    }
};