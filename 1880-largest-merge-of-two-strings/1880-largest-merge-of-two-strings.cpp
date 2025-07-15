class Solution {
public:
    string largestMerge(string word1, string word2) {
        
        string ans ;

        int i = 0 , j = 0 ;

        while(i<word1.size() && j<word2.size()){

            if(word1[i] > word2[j])
                ans.push_back(word1[i++]);

            else if(word1[i] < word2[j])
                ans.push_back(word2[j++]);

            else {
                
                int tempi = i , tempj = j ;
                // same case

                while(tempi < word1.size() && tempj<word2.size() && word1[tempi] == word2[tempj]){
                    tempi++,tempj++;
                }   

                if(tempi == word1.size())
                    ans.push_back(word2[j++]);

                else if(tempj == word2.size())
                    ans.push_back(word1[i++]);

                else if(word1[tempi] > word2[tempj])
                    ans.push_back(word1[i++]);

                else ans.push_back(word2[j++]); ;
            }
        }

        while(i<word1.size())
            ans.push_back(word1[i++]);

        while(j<word2.size())
            ans.push_back(word2[j++]);

        return ans ;        
    }
};