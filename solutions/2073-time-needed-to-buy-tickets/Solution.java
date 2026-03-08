class Solution {
    public int timeRequiredToBuy(int[] t, int k) {
        int n = t.length;
        int[] oc = new int[n];
        Deque<int[]> q = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            q.addLast(new int[]{i,t[i]});
        }
        int s=0;
        while(!q.isEmpty()){
            s++;
            int[] cur = q.pollFirst();
            cur[1]--;
            if(cur[1] == 0){
                if(cur[0] == k) return s;
            }
            else{
                q.addLast(cur);
            }
        }
        return -1;
    }
}