class Solution {
public:
    bool check(int bits,int ele){

        for(int i=0; i<32;i++){

            bool currPosBit = ele & (1<<i);
            bool inBits = bits & (1 << i);

            if(currPosBit && inBits)
                return true ;
        }

        return false ;
    }


    int longestNiceSubarray(vector<int>& nums) {
       
        int ans = 1;
        int i = 0 , j = 0 ;
        int bits = 0 ;  // bits from 1 to 32 
        // if we are having more than 2 bits in the same position 
        // (from 1 to 32) , means some elements in that subarray bitwise AND
        // will not be equal to 0 
        // so minimise the window 
        // APNA Solution : interview exp , upr wala , dry run , write bit representation of array


        while(j < nums.size()){

            while(check(bits,nums[j])){

                // minimise the window
                for(int k=0; k<32; k++){

                    bool currPosBit = (1 << k) & nums[i]  ;
                    if(currPosBit == 1){
                        /// clear this bit 
                        int mask = 1 << k ;
                        mask = ~mask ;
                        bits &= mask ;
                    }
                        
                }

                i++;
            }

            for(int k=0; k<32; k++){

                bool bit = nums[j] & (1<<k);
                if(bit){
                    bits |= (1<<k);
                }
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans ;
    }
};
