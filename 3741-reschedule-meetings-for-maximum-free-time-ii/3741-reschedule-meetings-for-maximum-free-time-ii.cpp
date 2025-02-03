class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> meetTime(n);
        for(int i = 0; i < n; ++i){
            meetTime[i] = endTime[i] - startTime[i];
        }
        
        vector<int> freeSlot;
        freeSlot.push_back(startTime[0]);
        for(int i = 1; i < n; ++i){
            freeSlot.push_back(startTime[i] - endTime[i - 1]);
        }
        freeSlot.push_back(eventTime - endTime[n - 1]);

        int maxFreeTime = 0;
        for(int i = 1; i < n + 1; ++i){
            maxFreeTime = max(maxFreeTime, freeSlot[i - 1] + freeSlot[i]);
        }

        vector<int> pre = freeSlot;
        vector<int> suf = freeSlot;
        for(int i = 1; i < n + 1; ++i){
            pre[i] = max(pre[i], pre[i - 1]);
        }
        for(int i = n - 1; i >= 0; --i){
            suf[i] = max(suf[i], suf[i + 1]);
        }

        auto check = [&](int i){
            if((i > 0) && (pre[i - 1] >= meetTime[i])) return true;
            if((i + 2 < n + 1) && (suf[i + 2] >= meetTime[i])) return true;
            return false;
        };

        for(int i = 0; i < n; ++i){
            if(check(i)){
                maxFreeTime = max(maxFreeTime, freeSlot[i] + meetTime[i] + freeSlot[i + 1]);
            }
        }
        
        return maxFreeTime;    
    }
};