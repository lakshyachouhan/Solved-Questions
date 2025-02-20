class Solution {
public:
    string s;
    int dp[11][2][1 << 10][2];

    int solve(int n, bool tight, int i, int digits, int mask, bool rep) {

        if(i >= digits)
            return rep ? 1 : 0;

        if(dp[i][tight][mask][rep] != -1)
            return dp[i][tight][mask][rep];
        
        int ub = tight ? s[i]-'0' : 9 ;
        int ans = 0;
        
        for(int ele = 0; ele <= ub; ele++){

            if(i == 0 && ele == 0)  
                continue;
            
            bool newTight = tight && (ele == s[i]-'0');
            bool newRep = rep;
            int newMask = mask;
            
            if(mask & (1 << ele))  newRep = true;
            
            else   newMask |= (1 << ele);
            
            ans += solve(n, newTight, i+1, digits, newMask, newRep);
        }
        
        return dp[i][tight][mask][rep] = ans;
    }

    int numDupDigitsAtMostN(int n) {

        int ans = 0;
        s = to_string(n);
        int places = s.size();

        for(int digits = 2; digits < places; digits++){
            
            memset(dp,-1,sizeof(dp));
            ans += solve(n, false, 0, digits, 0, false);
        }

        memset(dp,-1,sizeof(dp));
        ans += solve(n, true, 0, places, 0, false); // all digits of n  . tight is 1 
         
        return ans;
    }
};
