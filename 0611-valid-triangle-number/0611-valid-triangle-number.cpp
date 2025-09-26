class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ans = 0 ;
        int n = nums.size();

        for(int i=n-1; i>=2; i--){

            int j = 0 , k = i-1 ;

            while(j < k){

                if(nums[j] + nums[k] > nums[i]){
                    ans += k-j ;
                    k--;
                } 

                else j++;
            }
           
        }

        return ans ;
    }
};