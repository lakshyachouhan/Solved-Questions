#define ll long long 

class Solution {
public:
    void checkPrime(string &curr ,set<ll,greater<ll>> &st ){
        
        ll num = stoll(curr);

        if(num == 0 || num == 1)
                return ;

        for(ll i=2; i<=sqrt(num); i++){

            if(num%i == 0)
                return ;
        }

        st.insert(num);
    }
    
    long long sumOfLargestPrimes(string s) {

        set<ll,greater<ll>> st ;
        for(int i=0; i<s.size(); i++){

            string curr = "" ;
            for(int j=i; j<s.size(); j++){
                    curr += s[j];
                    checkPrime(curr,st);
            }
        }

        int count = 0 ;
        ll ans = 0 ;
        while(count <= 2 && !st.empty()){

            ans += *st.begin();
            st.erase(st.begin());
            count++;
        }

        return ans ;
    }
};