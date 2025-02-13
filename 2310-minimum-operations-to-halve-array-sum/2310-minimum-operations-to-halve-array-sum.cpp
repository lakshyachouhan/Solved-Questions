class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        // reducedSum = totalSum - (sum of all removed elements)
        priority_queue<double> maxHeap(nums.begin(),nums.end()) ;

        double total = accumulate(nums.begin(),nums.end(),0LL);
        double req = total / 2 ;
        double reduced = 0 ;
        int ans = 0 ;

        while(req > reduced){

            auto top = maxHeap.top();
            maxHeap.pop();

            double half = top/2.0 ;
            reduced += half ;
            maxHeap.push(half);
            ans++;
        }

        return ans ;
    }
};