class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int ans = 0 ;
        
        for(auto s:words){

            if(s.size() >= pref.size()){

                if(s.substr(0,pref.size()) == pref)
                    ans++;
            }
        }

        return ans ;
    }
};