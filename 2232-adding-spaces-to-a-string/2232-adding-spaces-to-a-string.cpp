class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string ans ;
        int spaIdx = 0 ;

        for(int i=0; i<s.size(); i++){

            if(spaIdx < spaces.size() && spaces[spaIdx] == i){
                ans.push_back(' ');
                spaIdx++;
            }

            ans.push_back(s[i]);
        }

        return ans ;
    }
};