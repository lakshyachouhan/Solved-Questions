#define ll long long 

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        ll ans = 0 ;
        ll sum = 0;
        unordered_map<int,int> mp ;

        for(int i=0; i<k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }  

        if(mp.size() == k)   ans = sum ;
        int i = 0 , j = k ;
        while(j < nums.size()){

            sum += nums[j];
            mp[nums[j]]++;

            sum -= nums[i];
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)    mp.erase(nums[i]);

            if(mp.size() == k)
                   ans = max(ans,sum) ;

            i++,j++;
        }

        return ans ;
    }
};