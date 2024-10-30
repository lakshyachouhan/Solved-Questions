class Solution {
public:
/* 
edge case 
text = "acbaaa"
Output 4
*/

    int maxRepOpt1(string text) {
        
        if(text.size() == 1)    return 1 ;
        unordered_map<char,int> freq ;
        for(auto ch:text)
            freq[ch]++;

        int ans = 0 ;
        for(int i=0; i<text.size(); i++){
            int allow = 0 ;
            for(int j=i+1; j<text.size(); j++){

                if(text[i] != text[j] && allow == 0){
                    allow = 1 ;
                }
                else if(text[i] != text[j])  break ;
         
                ans = max(ans,min(j-i+1,freq[text[i]]));
            }
        }

        for(int i=text.size()-1; i>=0; i--){
            int allow = 0 ;
            for(int j=i-1; j>=0; j--){

                if(text[i] != text[j] && allow == 0){
                    allow = 1 ;
                }
                else if(text[i] != text[j])  break ;
         
                ans = max(ans,min(i-j+1,freq[text[i]]));
            }
        }

        return ans ;
    }
};