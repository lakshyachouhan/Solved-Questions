class Solution {
public:
    int solve(string &s,char xdir, char ydir,int k){

        int x = 0 , y = 0;
        int ans = 0; 
        for(int i=0; i<s.size(); i++){

            char ch = s[i];

            if(ch == xdir )    x++;
            else if(ch == ydir) y++;
            else if((ydir == 'N' && ch == 'S') || (ydir == 'S' && ch == 'N')){

                if(k){
                    k-- ;
                    y++;
                }

                else y--;
            }

            else{
                if(k){
                    k-- ;
                    x++;
                }

                else x--;
            }

            ans = max(ans,x+y);
        }

        return ans ;
    }


    int maxDistance(string s, int k) {

        int ans = 0 ;
        ans = max(ans,solve(s,'N','E',k));
        ans = max(ans,solve(s,'S','E',k));
        ans = max(ans,solve(s,'N','W',k));
        ans = max(ans,solve(s,'S','W',k));

        return ans ;
    }
};