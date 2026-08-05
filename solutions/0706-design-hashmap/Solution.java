class MyHashMap {
    Integer[] map = new Integer[16];
    int cap = 16;
    public MyHashMap() {
        
    }
    
    public void put(int key, int value) {
        if(key>cap){
            int preCap = cap;
            while(key>cap){
                cap*=2;
            }
            Integer[] newMap = new Integer[cap];
            for(int i=0;i<preCap;i++){
                newMap[i]=map[i];
            }
            map = newMap;
        }
        map[key]=value;
    }
    
    public int get(int key) {
        if(key>cap)return -1;
        return map[key]==null ? -1: map[key];
    }
    
    public void remove(int key) {
        if(key<=cap)
        map[key]=null;    
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */