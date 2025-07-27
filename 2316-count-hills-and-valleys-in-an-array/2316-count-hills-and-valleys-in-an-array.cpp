class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int ans = 0 ;
        int i = 0 ;

        while(i < nums.size() && nums[i] == nums[i+1])
            i++;

        i++;
        while(i<nums.size()){
            
            int j = i ;
            while(j+1<nums.size() && nums[j] == nums[j+1]){
                j++;
            }

            j++;
            if(j < nums.size()){

                if(nums[i-1] < nums[i] && nums[i] > nums[j])
                    ans++;

                if(nums[i-1] > nums[i] && nums[i] < nums[j])
                    ans++;
            }

            i = j ;
        }

        return ans ;
    }
};