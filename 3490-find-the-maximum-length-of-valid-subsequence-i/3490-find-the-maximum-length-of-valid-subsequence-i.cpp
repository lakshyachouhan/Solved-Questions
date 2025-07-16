class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n = nums.size();
        int countOdd = 0 ;
        int countEven = 0 ;
        int oddEven = 0 ;
        int evenOdd = 0 ;

        for(auto ele:nums){

            if(ele&1){
                countOdd++;
                
                if(oddEven%2 == 0) oddEven++;
                if(evenOdd&1) evenOdd++;
            }

            else{
                countEven++;

                if(oddEven&1) oddEven++;
                if(evenOdd%2 == 0)  evenOdd++;

            }
        }

        return max({oddEven,evenOdd,countOdd,countEven});
    }
};