class Solution {
public:
    int solve(string &s,int p,string rem){

        if(s.size() < 2)
            return 0 ;

        int i = 0 , j = 0 ;
        int ans = 0 ;
        while(j < s.size()){

            s[i] = s[j];
            while(i > 0 && s[i] == rem[1] && s[i-1] == rem[0]){
                ans += p ;
                i -= 2 ;
            }

            j++;
            i++;
        }

        s = s.substr(0,i);
        return ans ;
    }

    int maximumGain(string s, int x, int y) {
        
        int ans = 0 ;
        if(x > y){
            ans  += solve(s,x,"ab");
            ans  += solve(s,y,"ba");
        }

        else{
            ans += solve(s,y,"ba");
            ans += solve(s,x,"ab");
        }

        return ans ;
    }
};