class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        vector<int> freq(501,0);

        for(auto ele:nums){
            freq[ele]++;
        }

        for(auto count:freq){

            if(count&1)
                return 0 ;
        }

        return true ;
    }
};