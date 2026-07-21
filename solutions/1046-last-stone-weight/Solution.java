class Solution {
    public int lastStoneWeight(int[] st) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int x:st)q.add(-x);
        while(q.size()>1){
            int x = q.poll();
            int y = q.poll();
            if(x==y)continue;
            q.add(x-y);
        }
        if(q.isEmpty())return 0;
        return -q.poll();
    }
}