class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int ans = 0 ;
        for(int i=0; i<nums.size()-1; i++){

            int sum = nums[i+1]-nums[i];
            for(int j=i+2;j <nums.size(); j++){

                if(nums[j]- nums[j-1] == sum)
                    ans++;
                
                else break ;

            }
        }

        return ans ;
    }
};