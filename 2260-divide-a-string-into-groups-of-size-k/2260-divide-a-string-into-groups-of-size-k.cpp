class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> ans ;

        string build = "";
        for(auto ch:s){

            build += ch ;

            if(build.size() == k){
                ans.push_back(build);
                build = "" ;
            }
        }

        if(build != ""){

            while(build.size() != k)
                build.push_back(fill);

            ans.push_back(build);
        }

        return ans ;
    }
};