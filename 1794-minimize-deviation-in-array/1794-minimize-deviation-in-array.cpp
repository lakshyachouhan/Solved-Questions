class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int mini = 1e9 + 1 ;
        for(auto &ele:nums){

            if(ele&1)
                ele *= 2 ;

            mini = min(mini,ele);
        }

        priority_queue<int> maxHeap(nums.begin(),nums.end());
        int ans = 1e9 + 1 ;

        while(1){

            auto top = maxHeap.top();
            maxHeap.pop();

            ans = min(ans,top-mini);

            if(top%2 == 0){
                top /= 2 ;
                maxHeap.push(top);
                mini = min(mini,top);
            }

            else break ;
        }

        return ans ;
    }
};