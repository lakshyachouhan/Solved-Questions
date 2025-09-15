class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        // instead of again & again searching in string or set 
        // use vector O(1)
        // Got feedback from the interviewer 
        vector<int> present(26,0);
        for(auto ch:brokenLetters){
            present[ch - 'a'] = 1 ;
        }

        int ans = 0 ;
        stringstream ss(text) ;
        string word ;

        while(ss >> word){

            // direct word mil rha hai 
            bool f = 1 ; 
            for(auto ch:word){

                if(present[ch - 'a'] == 1){
                    f = 0 ;
                    break ;
                }
            }

            if(f)
                ans++;
        }

        return ans ;
    }
};