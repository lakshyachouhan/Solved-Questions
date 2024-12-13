#define ll long long

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> minHeap ;

        for(int i=0; i<nums.size(); i++){
            minHeap.push({nums[i],i});
        }
        
        unordered_set<int> indexes ;

        ll ans = 0 ;
        while(!minHeap.empty()){

            auto top = minHeap.top();
            minHeap.pop();

            int ele = top.first ;
            int index = top.second ;

            if(indexes.find(index) == indexes.end()){
                ans += ele ;
                indexes.insert(index);
                indexes.insert(index-1);
                indexes.insert(index+1);
            }
        }

        return ans ;
    }
};