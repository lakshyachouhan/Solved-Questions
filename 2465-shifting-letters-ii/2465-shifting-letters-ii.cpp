class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> prefix(n,0);

        for(auto &i:shifts){

            int s = i[0] , e = i[1] ;
            int m = i[2] == 0 ? -1 : 1 ;

            prefix[s] += m ;
            
            if(e+1 < n) prefix[e+1] -= m ;  
        }

        for(int i=1; i<n; i++)
            prefix[i] += prefix[i-1];

        for(int i=0; i<n; i++){
            
            s[i] = ((s[i] - 'a' + prefix[i] + 26*10000) % 26 + 'a');

        }

        return s ;
    }
};