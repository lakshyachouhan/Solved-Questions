class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > minHeap;
        // {ele,{rowIndex,colIndex}}

        int maxi = INT_MIN , mini = INT_MAX; 
        for(int i=0; i<nums.size(); i++){
            minHeap.push({nums[i][0],{i,0}});
            maxi = max(maxi,nums[i][0]);
            mini = min(mini,nums[i][0]);
        }

        int ansStart = mini , ansEnd = maxi ;
        while(!minHeap.empty()){

            auto top = minHeap.top();
            int ele = top.first ;
            int rowI = top.second.first , colI = top.second.second ;
            minHeap.pop();  

            // kyoki minHeap hai , toh jo maxi hai current range ka , vo hamesha heap mein hoga ye ensure rahega 
            // mini -> top hai curr range ka
            // check diff  

            if(maxi - ele < ansEnd-ansStart){
                ansEnd = maxi ;
                ansStart = ele ;
            }

            if(colI + 1 < nums[rowI].size()){
                maxi = max(maxi,nums[rowI][colI+1]);
                minHeap.push({nums[rowI][colI+1],{rowI,colI+1}});
            }

            else break ;
        }

        return {ansStart,ansEnd} ;
    }
};