class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n-1; i++){

            if(nums[i] == nums[i+1]){
                nums[i] *= 2 ;
                nums[i+1] = 0 ;
                i++;
            }
        }

        int j = -1 ;
        for(int i=0; i<n; i++){

            if(nums[i] != 0){
                j++;
                nums[j] = nums[i];
            }
        }

        for(int i=j+1; i<n; i++)
            nums[i] = 0 ;

        return nums ;
    }
};