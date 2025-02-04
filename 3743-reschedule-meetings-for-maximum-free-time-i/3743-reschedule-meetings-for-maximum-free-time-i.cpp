#define ll long long 

class Solution {
public:
int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    
    ll n = startTime.size();
    vector<ll> spaces;
    spaces.push_back(startTime[0] - 0);

    for(ll i=1; i<n; i++){
        spaces.push_back( startTime[i] - endTime[i - 1]);
    }

    
    spaces.push_back(eventTime - endTime[n - 1]);


    ll curr = 0;
    for(ll i=0; i<=k ;i++)
            curr += spaces[i];
    

    ll ans = curr;
    for(ll i=k+1; i<spaces.size(); i++){
        curr += spaces[i] - spaces[i-k-1];
        ans = max(ans,curr);
    }

    return ans;
}
};