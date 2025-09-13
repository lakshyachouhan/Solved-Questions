class Solution {
public:
    bool isVowel(char &ch){

        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' ;
    }

    int maxFreqSum(string s) {
        
        vector<int> freq(26,0);
        int maxV = 0 , maxC = 0 ;
        for(auto ch:s){

            freq[ch-'a']++;

            if(isVowel(ch))
                maxV = max(maxV,freq[ch-'a']);

            else maxC = max(maxC,freq[ch-'a']);
        }

        return maxV + maxC ;
    }
};