#define ll long long 

class Solution {
public:
     static bool comp(tuple<int,int,int> &a, tuple<int,int,int> &b) {
        double first = (1.0 * get<0>(a)) / get<1>(a);
        double second = (1.0 * get<0>(b)) / get<1>(b);

        // if (first == second)
        //     return get<1>(a) > get<1>(b);  // secondary tie-breaker

        return first < second;
}

    
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {

        vector<tuple<int,int,int>> v ;
        for(int i=0; i<damage.size(); i++){

            int t = health[i]/power ;
            if(health[i]%power != 0)
                t++;

            v.push_back({t,damage[i],health[i]});
        }

        

        sort(v.begin(),v.end(),comp);

        // for(auto p:v){
        //     cout << p.first << " " << p.second << endl ;
        // }
        
        ll total = accumulate(damage.begin(),damage.end(),0LL);
        ll ans = 0 ;

        for(auto [t,d,h]:v){

            // ll h = v[i].first , d = v[i].second ;
            
            // ll k = h/power ;
            // if(h%power != 0)
            //         k++;
            
            ans += total*t ;
            total -= d ;            
        }

        return ans ;
    }
};