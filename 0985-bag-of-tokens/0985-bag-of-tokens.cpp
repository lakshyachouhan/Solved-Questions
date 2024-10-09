class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int ans = 0 ;
        int score = 0 ;
        int i = 0, j = tokens.size()-1 ;

        sort(tokens.begin(),tokens.end());

        while(i <= j){

            if(power >= tokens[i]){
                score++;
                ans = max(ans,score);
                power -= tokens[i];
                i++;
            }

            else if(score >= 1){
                score-- ;
                power += tokens[j];
                j--;
            }

            else break ;
        }

        // score -ve bhi jaa skta hai , start mei  ya beech mein khi
        return ans ;
    }
};