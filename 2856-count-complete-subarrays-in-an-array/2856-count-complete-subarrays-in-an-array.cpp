class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

       int ans = 0 ;
       int distinct = 0 ;
       int n = nums.size();
       unordered_set<int> st(nums.begin(),nums.end());
       distinct = st.size();
       st.clear();
       unordered_map<int,int> mp ;


       int i = 0 , j = 0 ;
       while(j < n){
           mp[nums[j]]++;

            while(mp.size() == distinct){
                ans += (1 + (n-1 - j));
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
       }

       return ans ;
    }
};