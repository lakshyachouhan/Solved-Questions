#include"bits/stdc++.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n = nums.size() ;
        // cout<< n << endl ;
        // cout<< nums.size() << endl ;
        int possiblesum = (n*(n+1))/2 ;

        int totalsum = accumulate(nums.begin(),nums.end(),0);

        int ans = possiblesum-totalsum ;
        // if(ans != 0)  return ans ;
        // else 
        // return ans!=nums[0] ? 0 : n+1 ;
        return ans ;
            }
};
    