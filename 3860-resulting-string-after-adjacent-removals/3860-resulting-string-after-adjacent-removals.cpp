class Solution {
public:
    string resultingString(string s) {
        
        string ans ;
        
        for(auto ch:s){

             if(!ans.empty()){

                int diff = abs(ch - ans.back());
                if(diff == 1 || diff == 25)
                    ans.pop_back();

                else ans.push_back(ch);
             }

            else ans.push_back(ch);
        }

        return ans ;
    }
};