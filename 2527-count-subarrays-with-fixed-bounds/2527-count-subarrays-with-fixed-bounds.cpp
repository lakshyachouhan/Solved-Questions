#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ll ans = 0 ;
        int minFound = -1 , maxFound = -1 , start = 0;

        // start -> tells ki yha se subarrays count 
        for(int i=0; i<nums.size(); i++){

            int ele = nums[i];
            if(ele > maxK || ele < minK){
                start = i+1 ;
                minFound = maxFound = -1 ;
            }

            if(ele == minK)
                minFound = i ;

            if(ele == maxK)    maxFound = i ;

            if(minFound != -1 && maxFound != -1)
                ans += min(minFound,maxFound) - start + 1 ;

        }

        return ans ;
    }


    // [7,2,3,4,1,5]
    // start = 1 
    // minFound = 4 , maxFound = 5 
    // ans -> 4 - 1 + 1= 4
};