// [ [1,20]  [2,4]  [6,8] ]
// LIS

class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){

        return a[1] < b[1] ;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);

        int ans = 1 ;
        int prevEnd = pairs[0][1];

        for(int i=1; i<pairs.size(); i++){

            if(pairs[i][0] > prevEnd){
                ans++;
                prevEnd = pairs[i][1];
            }
        }

        return ans ;
    }
};