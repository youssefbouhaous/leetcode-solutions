class MyHashSet {
    boolean[] set = new boolean[16];
    int cap =16;
    public MyHashSet() {
        
    }
    
    public void add(int key) {
        if(key>cap){
            int preCap = cap;
            while(cap<key)
            cap*=2;
            boolean[] newSet = new boolean[cap];
            for(int i=0;i<preCap;i++)newSet[i]=set[i];
            set = newSet;
        }
        set[key]=true;
    }
    
    public void remove(int key) {
        if(key<=cap)
        set[key]=false;
    }
    
    public boolean contains(int key) {
        if(key>cap)return false;
        return set[key];        
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */