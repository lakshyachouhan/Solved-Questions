class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n,0);
        vector<int> ans ;

        for(auto ele:nums){

            freq[ele]++;

            if(freq[ele] == 2)
                ans.push_back(ele);
        }

        return ans ;
    }
};