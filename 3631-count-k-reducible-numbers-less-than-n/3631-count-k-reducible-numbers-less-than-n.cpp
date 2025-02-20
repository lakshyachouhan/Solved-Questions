#define ll long long 
class Solution {
public:
    int MOD = 1e9 + 7 ;
    vector<ll> steps ; // agr itne 1's hai toh kitni steps 

    ll dp[801][801][2];
    ll solve(string& given,int k,bool tight,int i,int count1){

        if(i >= given.size()){

            if(tight || count1 == 0) return 0 ; 
            // matlab jo given tha wo ban gya 
            // lekin less than chaiye the 

            return steps[count1] < k ;
        }

        if(dp[i][count1][tight] != -1)
            return dp[i][count1][tight];

        int ub = tight ? given[i]-'0' : 1 ;
        ll ans = 0;

        for(int ele=0; ele<=ub; ele++){

            int newTight = tight && (ele == given[i]-'0') ;

            if(ele == 1)
                ans += solve(given,k,newTight,i+1,count1+1);

            else ans += solve(given,k,newTight,i+1,count1);
        }

        return dp[i][count1][tight] = ans%MOD ;        
    }

    int countKReducibleNumbers(string s, int k) {
        
        steps.resize(801,0);
        // steps[1] = 1 ;  // 1 bit wale ko 1 step

        for(int i=2; i<=800; i++){
            int count = __builtin_popcount(i);
            steps[i] = (1 + steps[count])%MOD ;
        }

        memset(dp,-1,sizeof(dp));
        ll ans = solve(s,k,1,0,0);
        return ans ;
    }
};