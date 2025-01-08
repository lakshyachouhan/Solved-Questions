class compare {
public:
    bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        
        if (a.first == b.first)
            return a.second.second < b.second.second;

        
        return a.first < b.first;
    }
};

class TaskManager {
public:
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> maxHeap;
    unordered_map<int, pair<int, int>> taskUpdate;
    unordered_set<int> remove;

    TaskManager(vector<vector<int>>& tasks) {
        
        for (auto i : tasks) {
            int uid = i[0], tid = i[1], p = i[2];
            maxHeap.push({p, {uid, tid}});
            taskUpdate[tid] = {uid, p};
        }
        
    }

    void add(int userId, int taskId, int priority) {
        
        maxHeap.push({priority, {userId, taskId}});
        taskUpdate[taskId] = {userId, priority};
        remove.erase(taskId);
        
    }

    void edit(int taskId, int newPriority) {
        
        int uid = taskUpdate[taskId].first;
        taskUpdate[taskId] = {uid, newPriority};
        maxHeap.push({newPriority, {uid, taskId}});
    }

    void rmv(int taskId) {
        
        taskUpdate.erase(taskId);
        remove.insert(taskId);
    }

    int execTop() {
        
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int p = top.first;
            int uid = top.second.first, tid = top.second.second;

            if (remove.count(tid)) {
                continue;
            }

            if (!taskUpdate.count(tid) || taskUpdate[tid].second != p || 
            taskUpdate[tid].first != uid) {
                continue;
            }

            taskUpdate.erase(tid);
            remove.insert(tid);
            return uid;
        }

        
        return -1;
    }
};
