#define ll long long 

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end()); // only increment possible
        ll l = 0 , r = 0 ;
        ll ans = 0 ;
        ll sum = 0 ;

        while(r < nums.size()){

            sum += nums[r];
            ll windowSize = r-l+1 ;
            ll currOp = windowSize * nums[r] ;
            
            // jab isme (r) wale element mein convert nhi kr pa rhe toh 
            // aage walo mein bhi not possible
            while(currOp - sum > k){
                sum -= nums[l];
                l++;
                currOp = (r-l+1) * nums[r];
            }

            ans = max(ans,r-l+1);
            r++;
        }

        return ans ;
    }
};