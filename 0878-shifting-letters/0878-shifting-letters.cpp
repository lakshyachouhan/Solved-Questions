class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        long long total = 0 ;
        for(int i=shifts.size()-1; i>=0; i--){

            total += shifts[i];
            s[i] = ((long long)(s[i]-'a' + total)%26)  + 'a';
        }

        return s ;
    }
};