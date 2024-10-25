class Solution {
public:
    static bool comp(const string &a, const string &b) {

        return a.size() < b.size();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(),folder.end(),comp);
        // so that parent folders come before in the array 
        // as parent folder will always have small length 
        
        unordered_set<string> st ;

        for(auto &s:folder){

            bool found = 0 ;
            string currFolder ;
            currFolder.push_back('/');
            int i = 1 ;
            // this also working  correctly 
            // int j = s.find('/',i) ;
            // while(j != -1){

            //     for(int k=i; k<j; k++) currFolder.push_back(s[k]);
            //     if(st.find(currFolder) != st.end()){
            //         found = 1 ;
            //         break ;
            //     } 

            //     currFolder.push_back('/');
            //     i = j+1 ;
            //     j = s.find('/',i) ;
            // }

            while(i < s.size()){

                if(s[i] == '/'){
                    // check abhi tak ka folder or parent folder 
                    if(st.find(currFolder) != st.end()){
                        found = 1 ;
                        break ;
                    }
                }

                currFolder.push_back(s[i]);
                i++;
            }

            if(!found)  st.insert(s);
        }

        return vector<string>(st.begin(),st.end());
    }
};