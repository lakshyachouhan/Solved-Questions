#define ll long long

class Solution {
public:
    bool isPossible(vector<int>& candies, long long k,ll mid){

        // mid candies ke k hisse ban skhte hai kya 

        ll count = 0 ;
        for(auto ele:candies){

            count += ele/mid ;

            if(count >= k)
                return 1 ;
        }

        return 0 ;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        
        // Brute Force : Each ans (Candy ) ke liye try 
        // like 1,2,3,4, de skhte hai kya 

        sort(candies.begin(),candies.end());
        ll n = candies.size();
        ll s = 1 ;
        ll e = candies[n-1];

        ll ans = 0 ;

        while(s <= e){

            ll mid = s+(e-s)/2 ;

            if(isPossible(candies,k,mid)){
                // mid candies de skte hai , each child ko 
                ans = mid ;
                s = mid+1 ;
            }

            else e = mid-1 ;
        }

        return ans ;
    }
};