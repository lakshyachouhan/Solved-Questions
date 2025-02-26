class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int ans = 0 ;
        int sum = 0 ;

        // maximum +ve sum 
        for(auto ele:nums){

            sum += ele ;
            ans = max(ans,abs(sum));

            if(sum < 0)
                sum = 0 ;
        }

        sum = 0 ;
        // maximum -ve sum 
        for(auto ele:nums){

            sum += ele ;
            ans = max(ans,abs(sum));

            if(sum > 0)
                sum = 0 ;
        }

        return ans ;
    }
};