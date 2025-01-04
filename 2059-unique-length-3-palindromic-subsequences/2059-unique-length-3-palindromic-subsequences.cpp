class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char,int> lastOcc , firstOcc;

        for(int i=0; i<s.size(); i++){
            lastOcc[s[i]] = i ; 

            if(firstOcc.count(s[i]) == 0){
                firstOcc[s[i]] = i ;
            }
        }

        int ans = 0 ;
        for(int i=0; i<s.size(); i++){

            char ch = s[i];

            if(firstOcc[ch] == i){
                // then calculate jitne ban skte hai 
                int l = lastOcc[ch];

                unordered_set<char> st;

                for(int k=i+1; k<l; k++)
                    st.insert(s[k]);

                ans += st.size();
            }

        }

        return ans ;
    }
};