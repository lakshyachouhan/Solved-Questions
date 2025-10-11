#define ll long long 

class Solution {
public:
    vector<ll> dp ;
    ll solve(vector<int> &power,int i){

        if(i >= power.size())
            return 0 ;

        if(dp[i] != -1)
            return dp[i];

        ll include = power[i];

        // include all same value indexes 
        int currIdx = i+1 ;
        while(currIdx < power.size() && power[i] == power[currIdx]){

            include += power[i];
            currIdx++;
        }

        int index = upper_bound(power.begin()+i,power.end(),power[i]+2) - power.begin();

        include += solve(power,index);

        ll exclude = solve(power,currIdx); // jo ki different value wala hoga i se 
        return dp[i] = max(include,exclude);
    }

    long long maximumTotalDamage(vector<int>& power) {
        
        dp.resize(power.size()+1,-1);
        sort(power.begin(),power.end());
        ll ans = solve(power,0);
        return ans ;
    }
};