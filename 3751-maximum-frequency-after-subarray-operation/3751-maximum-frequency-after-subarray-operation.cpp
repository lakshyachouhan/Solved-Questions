class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();
        int totalK = count(nums.begin(),nums.end(),k);
        
        int convertMax = 0; 
        
        // Try each candidate value v (from 1 to 50) 
        // that is different from k.
        // hr value ko convert & optimal solution wala subarray chose 
        // using kadane 
        for(int i=1; i<=50; i++){

            if(i == k)    continue ;
            int curr = 0 ;
            int maxSum = 0 ;

            for(auto ele:nums){

                if(ele == i)    curr += 1;  // freq increased as converted
                if(ele == k)    curr += -1 ; // k wali --

                maxSum = max(maxSum,curr);
                if(curr < 0)    curr = 0 ;
            }

            convertMax = max(convertMax,maxSum);            
        }


        return totalK + convertMax ;        
    }
};
