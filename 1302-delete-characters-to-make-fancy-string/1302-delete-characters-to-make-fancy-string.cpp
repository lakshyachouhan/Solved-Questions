class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.size();
        vector<int> count(n,0);
        int i = 0 ; 
        int j = 0 ;

        while(j < n){

            s[i] = s[j];
            j++;
            count[i] = 1 ;
            if(i >= 1 && s[i] == s[i-1])  count[i] += count[i-1];

            if(count[i] >= 3)   i--;
            i++;
        }

        return s.substr(0,i);
    }
};