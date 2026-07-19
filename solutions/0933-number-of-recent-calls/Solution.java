class RecentCounter {
    Deque<Integer> q;
    public RecentCounter() {
        q = new ArrayDeque<>();
    }
    
    public int ping(int t) {
        q.addLast(t);
        Deque<Integer> tq = new ArrayDeque<>();
        int ans = 0;
        while(!q.isEmpty() && t>=q.peekLast() && q.peekLast()>=t-3000){
            tq.addLast(q.pollLast()); ans++;
        }
        while(!tq.isEmpty())q.addLast(tq.pollLast());
        return ans;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */