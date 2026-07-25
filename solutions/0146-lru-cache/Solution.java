class LRUCache {
    Map<Integer,Integer> lru = new LinkedHashMap<>(0,0.75f,true);
    int cap;
    public LRUCache(int capacity) {
        cap = capacity;
    }
    
    public int get(int key) {
        return lru.getOrDefault(key,-1);
    }
    
    public void put(int key, int value) {
        if(lru.get(key)!=null)lru.put(key,value);
        else if(lru.size()<cap){
            lru.put(key,value);
        }else{
            Map.Entry<Integer,Integer> e = lru.entrySet().iterator().next();
            lru.remove(e.getKey());
            lru.put(key,value);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */