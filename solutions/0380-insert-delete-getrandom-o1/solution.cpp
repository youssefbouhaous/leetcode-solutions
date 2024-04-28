class RandomizedSet {
public:
    unordered_map<int,int>m;
    vector<int>d;
    int i=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m[val]==0){
            i++;
            m[val]=i;
            d.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m[val]==0){
            return false;
        }
        d[m[val]-1]=d.back();
        m[d.back()]=m[val];
        m[val]=0;
        d.pop_back();
        i--;
        return true;
    }
    
    int getRandom() {
        int i=rand()%(d.size());
        return d[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */