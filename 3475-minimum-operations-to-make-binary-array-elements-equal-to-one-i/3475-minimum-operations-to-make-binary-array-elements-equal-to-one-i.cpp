class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int i = 0 ;
        int ans = 0;
        while(i < nums.size()-2){
            
            if(nums[i] == 0){
                ans++ ;
                for(int k=i; k<=i+2; k++){
                    // cout << " andar" << endl ;
                    nums[k] = !nums[k];
                }
            }
            
            i++;
        }

        // cout << ans << endl ;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                    return -1 ;
        }
        
        return ans ;
    }
};