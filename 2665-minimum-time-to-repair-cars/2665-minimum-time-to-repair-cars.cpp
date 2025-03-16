#define ll long long 
class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars,ll mid){

        // kisi ka bhi time mid se jdaya nhi hona chaiye 
        // r * n^2 = mid (total time)
        ll count = 0 ;
        for(auto &r:ranks){

            ll curr = mid / r ;
            count += sqrt(curr); 
        }

        return count >= cars ;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
        ll s = 1;
        ll e = *max_element(ranks.begin(),ranks.end());
        e *= (1LL * cars * cars) ; // saari cars sabse jyada time  wale ne hi repair ki

        ll ans = -1 ;
        while(s <= e){

            ll mid = s+(e-s)/2 ;

            if(isPossible(ranks,cars,mid)){
                ans = mid ;
                e = mid-1 ;
            }

            else s = mid+1 ;
        }

        return ans ;
    }
};