class TaskManager {
public:
    unordered_map<int,int> taskIdPriority ;
    unordered_map<int,int> taskIdUserID; 
    // Very Imp Obs. : ek task ek hi userId se belong krega 

    map<int,set<int>> userTaskIds ; // after removing taskId
    priority_queue<tuple<int,int,int>> maxHeap ;

    TaskManager(vector<vector<int>>& tasks) {
        
        for(auto &v:tasks){

            int u = v[0] , t = v[1] ,  p = v[2] ;
            taskIdPriority[t] = p ;
            userTaskIds[u].insert(t);
            taskIdUserID[t] = u ;
            maxHeap.push({p,t,u});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        taskIdPriority[taskId] = priority ;
        taskIdUserID[taskId] = userId ;
        userTaskIds[userId].insert(taskId);
        maxHeap.push({priority,taskId,userId});
    }
    
    void edit(int taskId, int newPriority) {
        
        taskIdPriority[taskId] = newPriority ;
        // for(auto &[u,setTask]:userTaskIds){

        //     if(setTask.find(taskId) != setTask.end()){

        //         maxHeap.push({newPriority,taskId,u});
        //     }
        // }

        int u = taskIdUserID[taskId] ;
        maxHeap.push({newPriority,taskId,u});
    }
    
    void rmv(int taskId) {

        taskIdPriority.erase(taskId);
        int u = taskIdUserID[taskId] ;
        userTaskIds[u].erase(taskId) ;

    }
    
    int execTop() {
        
        while(!maxHeap.empty()){

            auto [p,t,u] = maxHeap.top();
            maxHeap.pop();

            if(taskIdPriority.count(t)){
                
                // check for updation 
                if(taskIdPriority[t] != p)
                    continue ;

                else{
                    rmv(t);
                    return u ;
                }
            }

        }

        return -1 ;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */