#define ll long long 

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        // left[i] -> sum of n min. elements including current index from left 
        // right[i] -> sum of n max. elements including current index from right

        ll size = nums.size(); // 3 * n
        ll n = size/3 ;

        priority_queue<ll,vector<ll>,greater<ll>> minHeap ; // to get sum of n max. elements
        priority_queue<ll> maxHeap ;

        vector<ll> left(size);
        vector<ll> right(size);
        ll sum = 0 ;

        for(ll i=0; i<n; i++){
            maxHeap.push(nums[i]);
            sum += nums[i];
        }

        left[n-1] = sum ;

        for(ll i=n; i<size; i++){

            maxHeap.push(nums[i]);
            sum += nums[i];

            sum -= maxHeap.top();
            maxHeap.pop();

            left[i] = sum ;
        }

        sum = 0;
        for(ll i=size-1; i>=size-n; i--){
            minHeap.push(nums[i]);
            sum += nums[i];
        }

        right[size-n] = sum ;
        for(ll i=size-n-1; i>=0; i--){

            minHeap.push(nums[i]);
            sum += nums[i];

            sum -= minHeap.top();
            minHeap.pop();

            right[i] = sum ;
        }

        ll ans = LLONG_MAX ;
        for(ll i=n-1; i<size-n; i++){

            ll curr = left[i] - right[i+1];
            ans = min(ans,curr);
        } 

        return ans ;
    }
};