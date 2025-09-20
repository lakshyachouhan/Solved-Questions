#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// PBDS ordered multiset of pairs (timestamp, uid)
using ordered_multiset = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Info {
public:
    int s, d, t, uid;
    Info(int so, int de, int ti, int id) : s(so), d(de), t(ti), uid(id) {}
};

class Router {
public:
    set<tuple<int,int,int>> entries;
    unordered_map<int, ordered_multiset> destinationTimeStamp; // simple multiset se bhi horha tha 
    // But TLE , check previous submission 

    queue<Info*> q;
    int size;
    int nextUid;

    Router(int memoryLimit) {
        this->size = memoryLimit;
        this->nextUid = 1;
    }

    bool addPacket(int source, int destination, int timestamp) {

        if (entries.find({source, destination, timestamp}) != entries.end())
            return false;

        if (q.size() == size) {
            Info* front = q.front();
            q.pop();

            auto &st = destinationTimeStamp[front->d];
            st.erase({front->t, front->uid});
            entries.erase({front->s, front->d, front->t});
            delete front;
        }

        int uid = nextUid++;
        Info* temp = new Info(source, destination, timestamp, uid);
        q.push(temp);
        destinationTimeStamp[destination].insert({timestamp, uid});
        entries.insert({source, destination, timestamp});

        return true;
    }

    vector<int> forwardPacket() {

        if (q.empty())
            return {};

        Info* front = q.front();
        q.pop();

        vector<int> ans = {front->s, front->d, front->t};

        auto &st = destinationTimeStamp[front->d];
        st.erase({front->t, front->uid});
        entries.erase({front->s, front->d, front->t});
        delete front;

        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {

        if (destinationTimeStamp.find(destination) == destinationTimeStamp.end())
            return 0;

        auto &st = destinationTimeStamp[destination];

        int right = st.order_of_key({endTime + 1, INT_MIN}); 
        int left  = st.order_of_key({startTime, INT_MIN}); 
        
        return right - left;
    }
};
