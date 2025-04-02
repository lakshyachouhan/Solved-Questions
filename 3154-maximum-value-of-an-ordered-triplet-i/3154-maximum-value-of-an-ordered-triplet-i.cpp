#define ll long long 

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        // (nums[i] - nums[j]) * nums[k] 
        // beech wale element (nums[j]) ko leke chale toh 
        // hr element ke liye prevGreater & nextGreater 
        
        int n = nums.size();
        vector<ll> nextGreater(n) , prevGreater(n) ;

        prevGreater[0] = -1 ;
        for(int i=1; i<n; i++){

            prevGreater[i] = max(nums[i-1] * 1LL,prevGreater[i-1]);
        }

        nextGreater[n-1] = -1 ;
        for(int i=n-2; i>=0; i--){

            nextGreater[i] = max(nums[i+1] * 1LL,nextGreater[i+1]);
        }

        ll ans = 0 ;
        for(int i=1; i<n-1; i++){

            ll curr = (prevGreater[i] - nums[i]) * nextGreater[i];
            ans = max(ans,curr);
        }

        return ans ;
    }
};