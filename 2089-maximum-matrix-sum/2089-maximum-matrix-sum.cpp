#define ll long long 

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        

        ll ans = 0 ;
        ll negCount = 0 ;
        ll mini = LLONG_MAX ;

        for(auto v:matrix){

            for(auto ele:v){

                if(ele < 0) negCount++;

                ans += abs(ele);
                mini = min(mini,abs(ele)*1LL);
            }
        }

        if(negCount&1){
            // toh sabse chote element ko negative rhne do
            // bakki sab +ve
            ans -= mini ;   // jo add wala
            ans -= mini ;   // -ve wala
        }

        return ans ;
    }
};