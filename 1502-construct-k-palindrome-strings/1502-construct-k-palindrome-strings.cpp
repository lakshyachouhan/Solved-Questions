class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size() < k)
            return 0 ;  // individual n can be atmost 

        vector<int> freq(26,0);

        for(auto ch:s)
            freq[ch - 'a']++;

        int oddFreqCount = 0 ;

        for(int i=0; i<26; i++){

            if(freq[i]&1)
                oddFreqCount++;
        }

        return oddFreqCount <= k ;
    }
};