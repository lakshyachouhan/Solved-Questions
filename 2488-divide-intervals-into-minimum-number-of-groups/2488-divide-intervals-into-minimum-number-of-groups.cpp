class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        map<int,int> marking ;
        for(auto &i:intervals){
            marking[i[0]]++;
            marking[i[1] + 1]--;
        }

        int ans = 0 ;
        int c = 0;
        for(auto &[t,status]:marking){

            c += status ;
            ans = max(ans,c);
        }

        return  ans ;

    }
};