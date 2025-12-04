class Solution {
public:
    int countCollisions(string directions) {

        int right = 0 ;
        int ans = 0 ;
        for(int i=0; i<directions.size(); i++){

            // count left right collison + right Stat. collison

            if(directions[i] == 'R')
                right++;

            else if(directions[i] == 'L'){

                if(right > 0){

                    ans += right-1 ;
                    ans += 2 ;
                    right = 0;
                }
            }

            else{
                ans += right ;
                right = 0 ;
            }
        }

        int left = 0 ;
        for(int i=directions.size()-1; i>=0; i--){

            // count left statio. collison

              if(directions[i] == 'L')
                left++;

            else if(directions[i] == 'R'){

                if(left > 0)
                    ans += left-1 ;

                left = 0 ;
            }

            else{
                ans += left ;
                left = 0 ;
            }
        }

        return ans ;
    }
};