class Solution {
public:
    // 11011000
    // 1 + 101100 + 0 
    //      1 + "" + 0 , 1 + 10 + 0

    string solve(string &s){

        vector<string> parts ;
        int count = 0 ;
        int start = 0 ;

        for(int i=0; i<s.size(); i++){

            if(s[i] == '1') count++;
            else count--;

            if(count == 0){
                // ab valid string mil gyi 
                // lekin uske andar bhi check krna hai 
                // toh first mein toh hamesha 1 hoga and last mein 0 
                // toh bakki check

                string inside = s.substr(start+1,i-start-1);
                string recKaAns = solve(inside);
                // andar nested string ko shi krke dega 

                parts.push_back('1' + recKaAns + '0');
                start = i+1;
            }
        }

        sort(parts.rbegin(),parts.rend()); // lexico
        string ans = "";
        for(auto str:parts)
            ans += str ;

        return ans ;
     }

    string makeLargestSpecial(string s) {
        
        // since the no. of 1's is greater than 0's in prefix 
        // so can we think of it as parentheses based ,  1-> '(' 0 -> ')'
        // so we need to form largest valid  parentheses , 
        // so nested parenthese should also follow same 
        string ans = solve(s);
        return ans ;
    }
};