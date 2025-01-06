#define ll long long 

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        priority_queue<ll> maxHeap ;
        priority_queue<ll,vector<ll>,greater<ll>> minHeap ;

        ll n = nums.size();
        vector<ll> left(n,-1);      // left se n min. elements ka sum
        vector<ll> right(n,-1);     // right ne n max. elements ka sum

        ll s = n/3 ;
        ll sum = 0 ;
        for(ll i=0; i<n; i++){

            maxHeap.push(nums[i]);
            sum += nums[i];

            if(maxHeap.size() > s){
                sum -= maxHeap.top();
                maxHeap.pop();

                // max. wala remove krenge toh minimum sum milega 
            }

            // size s ke equal ho tabhi update 
            if(maxHeap.size() == s)
                left[i] = sum ;
        }


        sum = 0 ;
        for(ll i=n-1; i>=0; i--){

            sum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > s){
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == s)
                 right[i] = sum ;
        }

        ll ans = LLONG_MAX ;
        for(ll i=0; i<n-1; i++){

            // cout << " index " << i << "  " << left[i] << "   "<< right[i] << endl;

            if(left[i] == -1 || right[i] == -1)
                continue;

            ll curr = left[i] - right[i+1];
            ans = min(ans,curr);
        }

        return ans ;    
    }
};