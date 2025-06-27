class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty())
            return 0 ;

        int ans = 0 ;
        unordered_map<int,bool> freq ;
        for(auto ele:nums){
            freq[ele] = true ;
        }

        for(auto ele:nums){
            if(freq.find(ele-1) != freq.end())
                freq[ele] = false ; // ye toh start nhi hoga 
        }
            
        // ab jo true hai , vo starting of seq btate hai toh wha se check
        for(auto it:freq){
            if(it.second == true){

                int count = 1;
                int curr = it.first ;
                while(freq.find(curr+1) != freq.end()){
                    curr = curr+1;
                    count++;
                }

                ans = max(ans,count);
            }
        }

        return ans ;
    }
};