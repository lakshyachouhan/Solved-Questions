class Solution {
public:
    static bool comp(vector<string>& a ,vector<string>& b){

        if(a[1] == b[1]){
            return a[0] == "OFFLINE" ; // O first then M 
        }

        return stoi(a[1]) < stoi(b[1]) ;
    }


    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        sort(events.begin(),events.end(),comp);
        set<int> online  ;

        for(int i=0; i<numberOfUsers; i++){
            online.insert(i);
        }

        unordered_map<int,int> activeTime ;
//  user_id -> time when they become online again

        int addAll = 0 ;
        vector<int> ans(numberOfUsers,0);

        for(auto e:events){
            
            string s = e[0]  , t = e[1] , ids = e[2] ;
            // cout << s << " "  << t << "   " << ids << endl ;
            int currTime = stoi(t);

               for(auto it = activeTime.begin(); it != activeTime.end();){

                        if(currTime >= it->second){
                               online.insert(it->first) ; // id
                               it = activeTime.erase(it);
                        }

                        else it++;
                }

            if(s == "MESSAGE"){

                if(ids == "ALL")    addAll++;
                else if(ids == "HERE"){

                    for(auto id:online)
                        ans[id]++;
                }

                else{

                    stringstream ss(ids);
                    string w ;

                    while(ss >> w){

                        string id = w.substr(2);
                        int num = stoi(id);
                        ans[num]++;
                    }
                }
            }

            else{
                int id = stoi(ids);
                online.erase(id);
                activeTime[id] = 60 + stoi(t);
            }
        }

        if(addAll){
            for(auto& ele:ans)
                    ele += addAll ;
        }

        return ans ;
    }
};