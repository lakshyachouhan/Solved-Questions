class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        // The CRUX of que :
        // Find the max. sum of subarray containing unique elements 

        int i = 0 ,j = 0 ;
        unordered_map<int,int> mp ; // ele -> freq 
        int sum = 0 ;
        int ans = 0 ;

        while(j < nums.size()){

            mp[nums[j]]++;
            sum += nums[j];

            while(mp[nums[j]] > 1){

                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            ans = max(ans,sum);
            j++;
        }

        return ans ;
    }
};