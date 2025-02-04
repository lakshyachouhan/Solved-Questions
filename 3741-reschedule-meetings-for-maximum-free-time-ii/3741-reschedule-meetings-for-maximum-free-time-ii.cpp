class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();
        vector<int> meetingTimes(n);
        vector<int> freeTime(n+1);

        for(int i=0; i<n; i++){

            meetingTimes[i] = endTime[i] - startTime[i];
        }

        freeTime[0] = startTime[0] - 0 ;
        freeTime[n] = eventTime - endTime[n-1];

        for(int i=1; i<n; i++){

            freeTime[i] = startTime[i] - endTime[i-1];
        }

        // for(auto i:freeTime)
        //     cout << i << "  " ;

        // first check left , right movement of a single meeting
        int ans = 0 ;
        for(int i=0; i<n; i++){

            int curr  = freeTime[i] + freeTime[i+1];
            ans = max(ans,curr);
        }

        // maximum freeTime kitna hai iss index tak 
        vector<int> prefixMax(n+1) , suffixMax(n+1) ;
        prefixMax[0] = freeTime[0];
        suffixMax[n] = freeTime[n];
        for(int i=1; i<n+1; i++){

            prefixMax[i] = max(prefixMax[i-1],freeTime[i]);
        }

        for(int i=n-1; i>=0; i--){

            suffixMax[i] = max(suffixMax[i+1],freeTime[i]);
        }

        auto check = [&](int i){

            if(i-1 >= 0 && prefixMax[i-1] >= meetingTimes[i]) return true ;
            if(i+2 <= n && suffixMax[i+2] >= meetingTimes[i]) return true ;

            return false ;
        };

        for(int i=0; i<n; i++){

            if(check(i)){
                // ith meeting ko khi bhi move kr skte hai 
                int curr =  freeTime[i] + meetingTimes[i] + freeTime[i+1];
                ans = max(ans,curr);
            }
        }

        return ans ;
     }
};