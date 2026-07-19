class RecentCounter {
    Deque<Integer> q;
    public RecentCounter() {
        q = new ArrayDeque<>();
    }
    
    public int ping(int t) {
        q.addLast(t);
        while(q.peekFirst()<t-3000)q.pollFirst();
        return q.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */