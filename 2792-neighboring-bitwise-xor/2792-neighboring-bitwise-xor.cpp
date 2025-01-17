class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        //OBSERVATION WALA 
        // Pehle pattern ka soch rhe the like 00 ,01,101
        // 0 ke baad 1 ya 1 ke baad 0 
        // Multiple tc 's pr , phir nhi  hua
        // toh direct xor krke dekh liya & DONE 
        int xor_sum = 0 ;

        for(auto ele :derived){

            xor_sum ^= ele ;
        }

        return xor_sum == 0 ;
    }
};