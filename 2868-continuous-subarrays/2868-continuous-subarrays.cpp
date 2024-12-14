#define ll long long 

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        ll ans = 0 ;
        priority_queue<pair<ll,int>> maxHeap ;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> minHeap ;
        
        int i = 0 , j =  0;
        while(j < nums.size()){

            maxHeap.push({nums[j],j});
            minHeap.push({nums[j],j});

            while(maxHeap.top().first - minHeap.top().first > 2){
                i++;
                while(maxHeap.top().second < i)    maxHeap.pop();
                while(minHeap.top().second < i)    minHeap.pop();
            }

            ans += j-i+1 ;
            j++;
        }

        return ans ;       
    }
};