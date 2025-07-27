class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int sum = nums[0] ;
        int i = 1 ;
        while(i < nums.size() && nums[i] == nums[i-1]+1){
            sum += nums[i];
            i++;
        }

        sort(nums.begin(),nums.end());
        int ans = sum ;
        for(auto ele:nums){

            if(ele < ans)
                continue ;

            if(ele == ans)
                ans++;

            else if(ele > ans)
                return ans ;
        }

        return ans ;
    }
};