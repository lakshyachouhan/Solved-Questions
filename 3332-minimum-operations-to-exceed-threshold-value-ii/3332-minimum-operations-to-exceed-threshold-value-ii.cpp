#define ll long long 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<ll,vector<ll> , greater<ll>> minHeap(nums.begin(),nums.end()) ;

        ll ans = 0 ;
        while(minHeap.size() >= 2){

            if(minHeap.top() < k){

                auto top1 = minHeap.top();
                minHeap.pop();

                auto top2 = minHeap.top();
                minHeap.pop();

                ll newEle = min(top1,top2) * 2 + max(top1,top2);
                minHeap.push(newEle);
                ans++;
            }

            else break ;
        }

        return ans ;
    }
};