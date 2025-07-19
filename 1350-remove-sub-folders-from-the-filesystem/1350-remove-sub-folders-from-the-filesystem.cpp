class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_map<string,bool> found ;
        vector<string> ans ;

        sort(folder.begin(),folder.end());

        for(auto &s:folder){

            string temp = "";
            for(int i=0; i<s.size(); i++){

                temp += s[i];

                if(found.count(temp) && i+1 < s.size() && s[i+1] == '/'){
                    // matlab ye subfolder hai
                    // ans mein toh nhi ayega 
                    break ;
                }
            }

            if(temp.size() == s.size()){
                ans.push_back(s);
                found[s] = 1 ;
            }
        }

        return ans ;
    }
};