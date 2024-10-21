class Solution {
public:
    int solve(string &s,int i,unordered_set<string> &st){

        if(i >= s.size())
            return st.size() ;
 
        int ans = 0 ;

        for(int j=i; j<s.size(); j++){

            string curr = s.substr(i,j-i+1);

            if(st.find(curr) == st.end()){
                st.insert(curr);
                ans = max(ans,solve(s,j+1,st));
                st.erase(curr);
            }
        }

        return ans ;
    }


    int maxUniqueSplit(string s) {
        
        unordered_set<string> st ;
        int ans = solve(s,0,st);    
        return ans ;
    }
};