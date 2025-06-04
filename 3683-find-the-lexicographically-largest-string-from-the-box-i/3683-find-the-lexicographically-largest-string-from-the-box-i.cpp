class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int maxi = word.size() - numFriends + 1;
        
        string ans = "";

        if(numFriends == 1)
            return word ;
        
        
        for (int i=0; i<word.size(); i++) {
            
                string curr = word.substr(i,maxi);
                ans = max(ans, curr);
                
        }
        
        return ans;
    }
};
