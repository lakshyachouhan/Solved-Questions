class Solution {
public:
    int maxSubstrings(string word) {

        // kyoki max. no. of substrings chaiye 
        // toh jo pehle jisse match hoti jayegi , banate jayenge 
        // Think , Think , Think 

        vector<int> marking(26,-1);
        int ans = 0;

        for(int i=0; i<word.size(); i++){

            char ch = word[i];
            if(marking[ch-'a'] != -1){

                if(i-marking[ch-'a']+1 >= 4){
                    ans++;
                    for(int i=0; i<26;i++)
                        marking[i] = -1 ;

                }
            }

            else marking[ch-'a'] = i ;
        }   

        return ans ;
    }
};