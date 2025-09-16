#define ll long long 
class Solution {
public:
    // ll GCD(ll a,ll b){

    //     while(a && b){

    //         if(a > b)
    //             a -= b ;

    //         else b -= a ;
    //     }

    //     return a == 0 ? b : a ;
    // }

    ll GCD(ll a, ll b) {

        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }

        return a;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        vector<int> ans ;
        for(auto ele:nums){

                ll curr = ele ;

                // newEle ko bhi uske piche wale 
                // se check krna padega 
                while(!ans.empty()){

                    ll back = ans.back();
                    ll gcd = GCD(curr,back);

                    if(gcd > 1){

                        ans.pop_back();
                        ll newEle = (back * curr ) / gcd; 
                        curr = newEle ;
                    }

                    else break ;
                }

                ans.push_back(curr);
        }
 
        return ans ;     
    }
};