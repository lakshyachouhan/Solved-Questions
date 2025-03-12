class Solution {
public:
    int maximumLength(string s) {
        
        // agr same type ke character hai , and unke occ check krna hai 
        // toh 2D vector

        // hr ch ki length ke kitne occurences hai 
        vector<vector<int>> v(26,vector<int>(s.size()+1,0));
        
        int len = 0 ;
        char prevCh = s[0];
        for(int i=0; i<s.size(); i++){

            if(s[i] == prevCh){
                len++;
                v[s[i] - 'a'][len]++;
            }

            else{
                len = 1 ;
                v[s[i] - 'a'][len]++;
                prevCh = s[i];
            }

        }

        int cumSum = 0 ; // prefixSum
        int ans = -1 ;

        for(int i=0; i<26; i++){

            cumSum = 0 ;
            for(int len=s.size(); len>=1; len--){

                cumSum += v[i][len] ;
                if(cumSum >= 3){
                    ans = max(ans,len);
                    break ;
                }
            }
        }

        return ans ;
    }
};