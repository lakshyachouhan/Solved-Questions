class comp{
    public:
    double profit(pair<int,int>& a){

        return (double)(a.first+1)/(a.second+1) - (double)(a.first)/(a.second);
    }


    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return profit(a) < profit(b) ; 
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> maxHeap ;
        // jisme increase krne pr sabse jyada change ho rha hai 
        // uske basis pr 

        for(auto i:classes){
            maxHeap.push({i[0],i[1]});
        }

        while(extraStudents--){

            auto top = maxHeap.top();
            maxHeap.pop();

            top.first += 1 ;
            top.second += 1 ;

            maxHeap.push(top);
        }

        double ans = 0 ;
        while(!maxHeap.empty()){

            auto [i,j] = maxHeap.top();
            maxHeap.pop();

            ans += (1.00*i/j);
        }

        return ans/classes.size() ;
    }
};