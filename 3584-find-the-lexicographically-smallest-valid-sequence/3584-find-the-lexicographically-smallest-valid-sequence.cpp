class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        vector<int> ans ;
        int n = word1.size();
        vector<int> aageKeKitneMatch(n) ;
        int match = 0;

        int i = word2.size()-1 ;  // w2
        int j ;     // w1
        for(j = n-1; j>=0; j--){

            aageKeKitneMatch[j] = match ;
            if(i>=0 && word1[j] == word2[i]){
                i-- ;
                match++;
            }
        }

        i = 0 ;
        j = 0;

        for(j=0; j<word1.size() && i<word2.size(); j++){

            if(word1[j] == word2[i]){
                i++;
                ans.push_back(j);
            }

            else{

                // isko match kara ke dekho 
                int left = word2.size()-i-1 ;
                cout << j << endl ;
                if(aageKeKitneMatch[j] >= left){
                    ans.push_back(j);
                    j++;
                    i++;
                    break ;
                }
            }
        }

            for(; j<word1.size() && i<word2.size(); j++){

                if(word2[i] == word1[j]){
                    ans.push_back(j);
                    i++;
                }
            }

        if(ans.size() == word2.size())  
            return ans ; 

        return {};       
    }
};