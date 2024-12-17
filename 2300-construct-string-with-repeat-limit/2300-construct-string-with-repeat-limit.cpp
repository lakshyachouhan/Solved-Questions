class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        priority_queue<pair<char,int>> maxHeap ;

        string ans ; 

        unordered_map<char,int> freq ;
        for(auto ch:s)  freq[ch]++;

        for(auto [ch,f]:freq){
            maxHeap.push({ch,f});
        }

        while(maxHeap.size() > 1){

            auto top1 = maxHeap.top();
            maxHeap.pop();

            auto top2 = maxHeap.top();
            maxHeap.pop();

            int mini = min(top1.second,repeatLimit);
            top1.second -= mini ;

            while(mini--){
                ans += top1.first ;
            }

            if(top1.second){
                ans += top2.first ;
                top2.second-- ;
            }

            if(top1.second) maxHeap.push(top1);
            if(top2.second) maxHeap.push(top2);
        }

        if(maxHeap.size() == 1){
            auto top = maxHeap.top();
            maxHeap.pop();

            int mini = min(top.second,repeatLimit);
            top.second -= mini ;

            while(mini--){
                ans += top.first ;
            }
        }
        
        return ans ;
    }
};