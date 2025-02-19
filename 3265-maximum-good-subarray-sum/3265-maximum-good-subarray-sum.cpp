#define ll long long 

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        // | a - b | = k 
        // a - b = +-k
        // a = k+b , -k+b
        int n = nums.size();

        // jab element as a (key) hai 
        // & array mein same elements possible hai , toh map ka use for prefix Sum

        // ith element mein i-1 tak ke elements ka sum in prefix 
        unordered_map<ll,ll> prefix; 
        ll ans = -1e15 ;
        ll sum = nums[0] ;
        prefix[nums[0]] = 0 ;

        for(int i=1; i<n; i++){
            
            if(prefix.find(nums[i]) == prefix.end())
                    prefix[nums[i]] = sum ;

            else prefix[nums[i]] = min(prefix[nums[i]],sum);
            // kyoki aagee subtract hoga 

            sum += nums[i] ;

            ll req = k + nums[i] ;
            if(prefix.count(req)){
                
                ll currAns = sum -  prefix[req] ;
                ans = max(ans,currAns);
            }

            ll req2 = -k + nums[i] ;
            if(prefix.count(req2)){
                
                ll currAns = sum -  prefix[req2] ;
                ans = max(ans,currAns);
            }

        }

        return ans == -1e15 ? 0 : ans;
    }
};