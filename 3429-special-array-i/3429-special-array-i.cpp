class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
    
        bool startOdd = 0 ;
        if(nums[0]&1)  
                 startOdd = 1 ;

        for(int i=0; i<nums.size(); i++){
            
            bool bit = nums[i]&1 ;

            if(startOdd){
                // odd hona chaiye 
                if(bit == 0)    return false ;
            }

            else{
                // even hona chaiye
                if(bit == 1)    return false ;
            }

            startOdd = !startOdd ;
        }

        return true ;
    }
};