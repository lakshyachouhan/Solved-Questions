class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int ans = 0 , i = 0 ;
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> minHeap ;
        // jiska endtime pehle hai usko pehle finish kro

        for(int day=1; day<=100000; day++){

            // remove events whose endtime is already reached 
            while(!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();

            // jo events iss din se start ho skte hai
            while(i < events.size() && events[i][0] == day){
                minHeap.push(events[i][1]);
                i++;
            }

            // attend event if any 
            // greedy , jiska endtime pehle hai , usko attend kr rhe hai
            if(!minHeap.empty()){
                minHeap.pop();
                ans++;
            }
        }

        return ans ;
    }
};