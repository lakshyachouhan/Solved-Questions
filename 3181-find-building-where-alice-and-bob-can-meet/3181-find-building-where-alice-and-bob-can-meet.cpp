class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        
        // Stack se 
        // bhi same like minHeap
        //  isme nextGreaterElement type rhega  while running 
        // last se iterate krnege in heights 
        // aur pop kreke ans nhi bana skte isliye stack ki jagah vector use 
        // ans each newQ ka usme search while running 

        // MinHeap se 

        int n = heights.size();
        vector<int> ans(queries.size(),-1) ;
        vector<vector<pair<int,int>>> newQ(n); // index -> {height,AnsqueryIndex}
        for(int i=0; i<queries.size(); i++){
            
            int l = queries[i][0] , r = queries[i][1] ;
            if(l > r)
                swap(l,r); // r hamesha bada index 

            int a = heights[l], b = heights[r] ;
            if(a < b || l == r)
                    ans[i] = r ;

            if(ans[i] == -1){
                newQ[r].push_back({max(a,b),i});
                // jo right wala index tha usse aage wala index chaiye 
                // + jo bhi inki maxvalue thi , usse badi value honi chaiye 
            }   
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap ; // isme newQ wali store while running 

        for(int i=0; i<n; i++){

            int curr = heights[i];
            while(!minHeap.empty() && minHeap.top().first < curr){
                ans[minHeap.top().second] = i ;
                minHeap.pop();
            }

            // ab age wale index pr iska ans mil skta hai 
            for(auto p:newQ[i]){
                minHeap.push(p);
            }
        }

        return ans ;
    }
};