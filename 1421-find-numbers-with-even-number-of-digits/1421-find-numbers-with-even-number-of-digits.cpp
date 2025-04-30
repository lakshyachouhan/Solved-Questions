class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int ans = 0 ;

        for(auto ele:nums){

            int c = 0 ;
            while(ele){
                c++;
                ele /= 10 ;
            }

            if(c%2 == 0)
                ans++;
        }

        return ans ;
    }
};