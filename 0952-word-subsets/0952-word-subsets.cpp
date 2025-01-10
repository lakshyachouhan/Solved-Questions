class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // hr character ki max. frequency se check 
        vector<string>  ans ;
        vector<int> max_freq(26,0);

        for(int i=0; i<words2.size(); i++){

            vector<int> curr(26,0);
            for(auto ch:words2[i]){
                curr[ch-'a']++;
                max_freq[ch-'a'] = max(max_freq[ch-'a'],curr[ch-'a']);
            }

        }

        for(auto s:words1){

            vector<int> curr(26,0);
            for(auto ch:s)
                curr[ch-'a']++;

            bool f = 1 ;
                for(int j=0; j<26; j++){

                    if(max_freq[j] > curr[j]){
                        f = 0 ;
                        break ;
                    }
                }

            if(f)
                ans.push_back(s);
        }

        return ans ;        
    }
};