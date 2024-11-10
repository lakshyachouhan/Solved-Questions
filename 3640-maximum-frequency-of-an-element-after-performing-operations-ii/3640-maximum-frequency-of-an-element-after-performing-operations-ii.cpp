#define ll long long 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<ll, int> diff;
        map<ll, int> freq;
        int maxFreq = 0;
        
        for(int ele : nums) {
            ll mini = max(0LL, (ll)ele - k);
            ll maxi = (ll)ele + k;
            
            diff[mini]++;
            diff[maxi + 1]--;
            freq[ele]++;
            maxFreq = max(maxFreq, freq[ele]);
        }
        
        int maxiAns = 0;
        int curr_sum = 0;
        
        set<ll> p;
        for(auto &[ele, f] : diff) p.insert(ele);
        for(auto &[ele, f] : freq) p.insert(ele);
        
        for(ll ele : p) {
            
            curr_sum += diff[ele];
            if(curr_sum > 0) {
                maxiAns = max(maxiAns, min(curr_sum, freq[ele] + numOperations));
            }
        }
        
        return min(maxiAns, maxFreq + numOperations);
    }
};
