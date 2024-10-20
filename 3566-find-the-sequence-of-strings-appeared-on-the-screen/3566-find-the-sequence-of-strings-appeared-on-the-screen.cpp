class Solution {
public:
    vector<string> stringSequence(string target) {
        
        vector<string> ans ;

        string curr = "a" ;
        int i = 0 ;

        while(i < target.size()){

            ans.push_back(curr);
            if(curr[i] == target[i]){

                if(curr == target){
                    return ans ;
                }

                else{
                    curr.push_back('a');
                    i++;
                }
            }

            else curr[i] += 1 ;
        }

        return ans ;
    }
};