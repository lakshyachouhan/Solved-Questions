class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> diff(n+1,0) ;

        for(auto i:shifts){

            int s = i[0] , e = i[1] , dir = i[2];

            if(dir == 0){
                diff[s] += -1 ;
                diff[e+1] += 1 ;
            }

            else{
                diff[s] += 1 ;
                diff[e+1] += -1 ;
            }
        }

        for(int i=1; i<n; i++)
            diff[i] += diff[i-1];

        for(int i=0; i<n; i++){
            
            int index = s[i]-'a' ; // 0 to 26 

            int newVal = (index + diff[i] + 10000*26)%26 ;
            s[i] = newVal + 'a' ;
        }

        return s ;
    }
};