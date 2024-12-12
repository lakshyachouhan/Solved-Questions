#define ll long long

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<ll> maxHeap(gifts.begin(),gifts.end());

        while(k--){

            auto top = maxHeap.top();
            maxHeap.pop();

            ll sq = floor(sqrt(top));
            maxHeap.push(sq);
        }

        ll ans = 0 ;
        while(!maxHeap.empty()){

            ans += maxHeap.top();
            maxHeap.pop();
        }

        return ans ;
    }
};