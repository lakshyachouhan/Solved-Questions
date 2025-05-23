#define ll long long 

class Solution {
public:
     ll maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {

        // kisi bhi do nodes pr operation kr skte hai , no need 
        // of the edge 
        // kyoki spanning tree hai , beech ki jo nodes hogi unpe even no. of 
        // xors honge , and they will cancel each other 
        vector<int> profit ;
        ll normalSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            profit.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }
        
        sort(profit.begin(), profit.end(), greater<int>());
        
        for (int i = 0; i < profit.size()-1; i += 2) {

            ll pairSum = profit[i] + profit[i + 1];
            
            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }

        return normalSum;


        // Optimal O(N) & O(1)
        // ll  sum = 0;
        // int count = 0;
        // int minNukasan = INT_MAX;

        // for (ll num : nums) {

        //     if((num^k) > num) {
        //         count++;
        //         sum += (num^k);
        //     } else {
        //         sum += num;
        //     }

        //     minNukasan = min((long long)minNukasan, abs(num - (num ^ k)));
        // }

        // if(count%2 == 0)
        //     return sum;

        // return sum - minNukasan;
    }
};