class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        vector<int> diff ;
        for(int i=0; i<s1.size(); i++){

            if(s1[i] != s2[i])
                diff.push_back(i);

            if(diff.size() > 2) 
                return false ;
        }

        if(diff.size() == 2){

            int i = diff[0] , j = diff[1];
            if(s1[j] == s2[i] && s1[i] == s2[j])
                return true ;

            else return false ;
        }

        if(diff.size() == 0 )
             return 1 ;   

        return 0 ; // diff.size() == 1     
    }
};