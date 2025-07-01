class Solution {
public:
    int possibleStringCount(string word) {
        
        int ans = 1 ;

        for(int i=0; i<word.size(); ){

            int j = i+1 ;
            while(j < word.size() && word[i] == word[j])
                j++;

            int count = j-i ;
            if(count > 1)
                ans += count-1 ;

            i = j ;
        }

        return ans ;
    }
};