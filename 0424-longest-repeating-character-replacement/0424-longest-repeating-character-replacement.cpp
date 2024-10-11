class Solution {
public:
    int characterReplacement(string s, int k) {
        
       
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            int freq[26] = {0};
            int maxFreq = 0 ;
            for(int j=i; j<s.length(); j++){

                // cout << s[j] - 'A' << endl ;
                freq[s[j]-'A']++;
                maxFreq = max(maxFreq,freq[s[j]-'A']);
                if(j-i+1 - maxFreq > k) break ;
                ans = max(ans,j-i+1);
            }
        }

        return ans ;
    }
};