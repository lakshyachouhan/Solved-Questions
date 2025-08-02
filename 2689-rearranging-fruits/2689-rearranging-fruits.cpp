#define ll long long 

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        ll ans = 0 ;
        unordered_map<int,int> mp ; // freq1 - freq2 

        for(auto ele:basket1)
            mp[ele]++;

        for(auto ele:basket2)
            mp[ele]--;

        vector<int> v ;
        int mini = 1e9 ;
        for(auto [ele,f]:mp){

            mini = min(mini,ele);
            if(f&1)
                return -1 ;

            // half elements swap honge 
            // kyoki equal krna hai 
            int count = abs(f/2);
            while(count--){
                v.push_back(ele);
            }
        }

        sort(v.begin(),v.end());
        for(int i=0; i<v.size()/2; i++){

            // ya toh v[i] ko use krke swap 
            // agr v[i] very large 
            // toh jo bhi global min. element hai 
            // usko use krke swap 
            // 2 baar use hoga 
            ans += min(v[i],2 * mini);
        }

        return ans ;
    }
};