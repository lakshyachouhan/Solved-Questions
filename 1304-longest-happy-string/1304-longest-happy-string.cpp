class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       
        priority_queue<pair<int,char>> maxHeap ; // {freq,char}

        if(a > 0)   maxHeap.push({a,'a'});
        if(b > 0)   maxHeap.push({b,'b'});
        if(c > 0)   maxHeap.push({c,'c'});

        string ans ;
        while(maxHeap.size() > 1){

            auto top1 = maxHeap.top();
            maxHeap.pop();

            auto top2 = maxHeap.top();
            maxHeap.pop();

            if(top1.first >= 2){
                ans.push_back(top1.second);
                ans.push_back(top1.second);
                top1.first -= 2 ;
            }
            else{
                ans.push_back(top1.second);
                top1.first-- ;
            }

            // yha pe catch hai , greedy nhi chale ga 
            if(top2.first >= 2 && top2.first > top1.first){
                ans.push_back(top2.second);
                ans.push_back(top2.second);
                top2.first -= 2 ;
            }
            else{
                ans.push_back(top2.second);
                top2.first-- ;
            }

            if(top1.first) maxHeap.push(top1);
            if(top2.first) maxHeap.push(top2);
        }

        if(maxHeap.size() == 1){
            auto top1 = maxHeap.top();
            maxHeap.pop();

            if(top1.first >= 2){
                ans.push_back(top1.second);
                ans.push_back(top1.second);
                top1.first -= 2 ;
            }
            else{
                ans.push_back(top1.second);
                top1.first-- ;
            }
        }

        return ans ;
    }
};