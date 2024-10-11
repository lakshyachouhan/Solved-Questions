class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        map<int,int> chairLeaveTime ;
        int ch = 0 ;

        vector<pair<pair<int,int>,int> > timesIndex(times.size()) ;

        for(int i=0; i<times.size(); i++){

            timesIndex[i] = {{times[i][0],times[i][1]},i};
        }

        sort(timesIndex.begin(),timesIndex.end());

        for(int i=0; i<timesIndex.size(); i++){

            int arr = timesIndex[i].first.first;
            int leav = timesIndex[i].first.second;
            bool sit = 0 ;

            for(auto &[chair,pl]:chairLeaveTime){

                if(arr >= pl){
                    pl = leav ;
                    if(targetFriend == timesIndex[i].second){
                        return chair ;
                    }

                    sit = 1 ;
                    break ;
                }
            }

            if(sit == 0){
                chairLeaveTime[ch] = leav ;
                if(targetFriend == timesIndex[i].second){
                        return ch ;
                    }
                ch++;
            }
        }

        return -1 ;
    }
};