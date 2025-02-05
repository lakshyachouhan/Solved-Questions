class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        unordered_map<char,int> mp1, mp2;
        
        for(char ch : word1) mp1[ch]++;
        for(char ch : word2) mp2[ch]++;
        

        for(auto [ch1, _] : mp1) {
            for(auto [ch2, _] : mp2) {

                int unique1 = mp1.size();
                int unique2 = mp2.size();
                
                if(ch1 != ch2) {
                    if(mp1[ch1] == 1) unique1--;
                    if(mp2[ch2] == 1) unique2--;
                    
                    if(!mp1.count(ch2)) unique1++;
                    if(!mp2.count(ch1)) unique2++;
                }
                
                if(unique1 == unique2) return true;
            }
        }
        
        return false;
    }
};