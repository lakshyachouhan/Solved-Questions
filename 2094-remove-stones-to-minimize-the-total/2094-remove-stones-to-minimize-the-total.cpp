class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> maxHeap(piles.begin(),piles.end()) ;
        int ans = 0 ;

        while(k--){

            auto top = maxHeap.top();
            maxHeap.pop();

            int val = floor(top/2);
            maxHeap.push(top - val);
        }

        while(!maxHeap.empty()){

            ans += maxHeap.top();
            maxHeap.pop();
        }

        return ans ;
    }
};