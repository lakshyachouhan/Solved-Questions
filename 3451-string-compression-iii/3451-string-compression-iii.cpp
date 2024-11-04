class Solution {
public:
    string compressedString(string word) {
        
        string ans ;
        int i = 0 ;

        while(i < word.size()){

            int j = i+1 ;
            while(j<word.size() && word[i] == word[j]){
                j++;
                if(j-i == 9)  break ;
            }

            int count = j-i ;
            ans += count + '0';
            ans += word[i];
            i = j ;
        }

        return ans ;
    }
};