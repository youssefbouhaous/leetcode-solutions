class TaskManager {
    private:
    set<pair<int,int>>q;
    map<int,int>mp;
    map<int,int>mpi;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto x:tasks){
            q.insert({x[2],x[1]});
            mp[x[1]]=x[2];
            mpi[x[1]]=x[0];
        }
    }
    
    void add(int i, int t, int p) {
        q.insert({p,t});
        mp[t]=p;
        mpi[t]=i;
    }
    
    void edit(int t, int p) {
        auto it=q.find({mp[t],t});
        q.erase(it);
        mp[t]=p;
        q.insert({p,t});
    }
    
    void rmv(int t) {
        q.erase({mp[t],t});
    }
    
    int execTop() {
        if(q.size()==0)return -1;
        auto it=*(--q.end());
        q.erase(it);
        return mpi[it.second];
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