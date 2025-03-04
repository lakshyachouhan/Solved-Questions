#define ll long long 

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {

        map<ll,ll> mp ;
        // vector<ll> diff(range+1,0);

        ll n = bounds.size();
        for(int i=0; i<bounds.size(); i++){

            int mini = bounds[i][0] - original[i];
            int maxi = bounds[i][1] - original[i]; 

            mp[mini]++;
            mp[maxi+1]--;            
        }

        ll ans = 0 ;
        ll prevEle = mp.begin()->first ;
        ll diff = 0 ;
        
        for(auto [ele,count]:mp){

            // cout << ele << "   " << count << endl ;
            // cout << diff << endl ;
            if(diff == n){
                ans += ele - prevEle ;
            }

            diff += count ;
            prevEle = ele ;
        }

        return ans ;        
    }
};