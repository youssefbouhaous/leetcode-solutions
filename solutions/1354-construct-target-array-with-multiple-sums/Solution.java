class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> q = Arrays.stream(target)
                                    .boxed()
                                    .collect(Collectors.toCollection(
                                        () -> new PriorityQueue<>(Collections.reverseOrder())
                                    ));
        long s = 0;
        for (int x : target) {
            s += x;
        }
        int n = target.length;
        while(q.peek()>1){
            long p = q.poll();
            long rest = s-p;
            if(p<rest || rest==0)return false;
            if(rest == 1)return true;
            int pre = (int)(p%rest);
            if(pre==0)return false;
            q.add(pre);
            s=s-p+pre;
        }
        return s == n;
    }
}