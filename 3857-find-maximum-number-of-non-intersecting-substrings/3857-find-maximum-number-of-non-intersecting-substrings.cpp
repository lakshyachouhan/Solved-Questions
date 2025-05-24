#define ll long long 

class Solution {
public:
    int maxSubstrings(string word) {

        ll n = word.size();
        vector<vector<ll>> indexes(26);

        for(ll i=0; i<n; i++){
            indexes[word[i]-'a'].push_back(i);
        }

        vector<ll> next(n,-1);
        for(ll i=0; i<n; i++){

            char ch = word[i];
            auto it = lower_bound(indexes[ch-'a'].begin(),indexes[ch-'a'].end(),i+3);
            if(it != indexes[ch-'a'].end())
                next[i] = *it ;
        }

        vector<ll> dp(n+1,0);
        for(ll i=0; i<n; i++){

            ll k = next[i];
            if(k != -1)
                dp[k+1] = max(dp[k+1],dp[i] + 1);
            
            dp[i+1] = max(dp[i],dp[i+1]);
        }

        return dp[n];
    }
};