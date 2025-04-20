class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        // x rabbits have seen y colors 
        // mp[y] = x ; // y+1 total possible
        // count = ceil( x / (y+1)) * (y+1) ;

        unordered_map<int,int> mp ;
        for(auto &ele:answers)
            mp[ele]++;

        int ans = 0 ;

        for(auto [rabbits,colorOfSameType]:mp){

            int curr = ceil(1.00*colorOfSameType/(rabbits+1));
            curr *= (rabbits+1) ;

            ans += curr ;
        }

        return ans ;
    }
};