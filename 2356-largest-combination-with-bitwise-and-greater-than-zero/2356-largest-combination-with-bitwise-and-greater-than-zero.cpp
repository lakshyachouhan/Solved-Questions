class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        // BitWise AND matlab 1 & 1 = 1
        // bakki sab combination mein 0 
        // hr position ke liye 1 count -> ans -> maximum count
        // Agr jo test case hai , usme sabka bitwise likh lete toh 
        // direct dikh jata 
        int ans = 0 ;
        for(int i=0; i<32; i++){

            int count = 0 ;
            for(auto ele:candidates){

                if(ele & (1<<i))    count++;
            }

            ans = max(ans,count);
        }

        return ans ;
    }
};