class Solution {
public:
    bool isVowel(char ch){

        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' ;
    }

    bool isValid(string word) {
        
        if(word.size() < 3)
            return 0 ;

        bool vowel = 0 , conso = 0 ;
        for(auto ch:word){

            if(isalpha(ch)){

                if(isVowel(ch))
                    vowel = 1 ;

                else conso = 1 ;
            }

            else if(isdigit(ch))
                continue ;

            else return false ;
        }

        return vowel && conso ;
    }
};