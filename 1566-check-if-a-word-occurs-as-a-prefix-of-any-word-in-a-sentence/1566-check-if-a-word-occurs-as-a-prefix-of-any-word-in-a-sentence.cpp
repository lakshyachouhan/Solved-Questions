class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        stringstream ss(sentence);
        string word ;
        int len = searchWord.length() ;
        int i = 1;

        while(ss >> word){

            if(word.length() >= len){
                if(word.substr(0,len) == searchWord){
                    return i ;
                }
            }

            i++;
        }
        

        return -1 ;
    }
};