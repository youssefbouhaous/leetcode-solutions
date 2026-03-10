class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>(stones.length,Collections.reverseOrder());
        for(Integer i: stones )q.add(i);
        while(q.size()>1){
            Integer a=q.poll();
            Integer b=q.poll();
            if(a.equals(b))continue;
            q.add(Math.abs(a-b));
        }
        return q.size() ==1 ? q.poll():0;
    }
}