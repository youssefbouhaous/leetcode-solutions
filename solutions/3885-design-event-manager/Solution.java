class EventManager {
    PriorityQueue<int[]> q = new PriorityQueue<>((a,b)->{
        if(a[0]==b[0]){
            return b[1]-a[1];
        }
        return b[0]-a[0];
    });
    Map<Integer,Integer> mp = new HashMap<>();
    public EventManager(int[][] events) {
        for(int[] a:events){
            q.add(new int[]{a[1],-a[0]});
            mp.put(a[0],a[1]);
        }
    }
    
    public void updatePriority(int eventId, int newPriority) {
        q.add(new int[]{newPriority,-eventId});
        mp.put(eventId,newPriority);
    }
    
    public int pollHighest() {
        while(!q.isEmpty()){
            int[] a=q.poll();
            if(mp.get(-a[1])!=null && mp.get(-a[1])==a[0]){
                mp.remove(-a[1]);
                return -a[1];
            }
        }
        return -1;
    }
}

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager obj = new EventManager(events);
 * obj.updatePriority(eventId,newPriority);
 * int param_2 = obj.pollHighest();
 */