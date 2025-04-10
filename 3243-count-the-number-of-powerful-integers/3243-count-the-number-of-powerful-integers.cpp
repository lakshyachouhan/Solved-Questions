#define ll long long 

class Solution {
public:
    ll dp[20][2];
    ll solve(string &given, string &s, bool tight, int limit, int i){

        if(given.size() < s.size())
            return 0;
        
        if(i >= given.size())
            return 1;

        if(dp[i][tight] != -1)
            return dp[i][tight];
        
        ll ans = 0;
        int ub = tight == 1 ? given[i] - '0' : limit;
        ub = min(ub, limit);    // sab limit se chote hona chiye 
        
        int diff = given.size() - s.size();  // dry run 
        if(i >= diff){
            // We are in the suffix part
            // the remaining digits must match s exactly. 
            // s wali banana start ho chuki hai 
            int indexInS = i - diff;
            int reqDigit = s[indexInS] - '0';

            if(ub < reqDigit)
                return 0LL;

            bool newTight = (tight && (reqDigit == given[i] - '0'));
            return solve(given, s, newTight, limit, i + 1);
        }
        

        for(int ele = 0; ele <= ub; ele++){
            
            bool newTight = (tight && (ele == given[i] - '0'));
            ans += solve(given, s, newTight, limit, i + 1);
        }
        
        return dp[i][tight] =  ans;
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        string a = to_string(start - 1);
        string b = to_string(finish);
        
        bool tight = true;

        memset(dp,-1,sizeof(dp));
        ll ans1 = solve(a, s, tight, limit, 0);
        memset(dp,-1,sizeof(dp));
        ll ans2 = solve(b, s, tight, limit, 0);
        
        // cout << ans2 << "  " << ans1 << endl ;
        return ans2 - ans1;
    }
};
