class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        // elements may be repeating , isliye indexes store
        int maxi1 = -1 , maxi2 = -1 ;
        int mini1 = -1 , mini2 = -1 ;

        for(int i=0; i<nums.size(); i++){

            int ele = nums[i];
            if(maxi1 == -1 || ele > nums[maxi1]){
                maxi2 = maxi1 ;
                maxi1 = i ;
            }

            else if(maxi2 == -1 || ele > nums[maxi2]){
                maxi2 = i ;
            }
        }

        for(int i=0; i<nums.size(); i++){
            
            if(i == maxi1 || i == maxi2)    continue ;
            int ele = nums[i];
            if(mini1 == -1 || ele < nums[mini1]){
                mini2 = mini1 ;
                mini1 = i ;
            }

            else if(mini2 == -1 || ele < nums[mini2]){
                mini2 = i ;
            }
        }

        return (nums[maxi1]*nums[maxi2]) - (nums[mini1]*nums[mini2]);
    }
};