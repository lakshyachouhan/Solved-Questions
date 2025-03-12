class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        // int pos = 0 , neg = 0 ;

        // for(auto ele:nums){

        //     if(ele > 0)
        //         pos++;

        //     else if(ele < 0)
        //         neg++;
        // }

        // return max(pos,neg);

        // sorted
        // Binary Search 
        int first0 = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int firstPos = upper_bound(nums.begin(),nums.end(),0)- nums.begin();

        int pos = nums.size() - firstPos ;
        int neg = first0 ;

        return max(pos,neg);
    }
};