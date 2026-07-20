class Solution {
    public int calPoints(String[] op) {
        Deque<Integer> q = new ArrayDeque<>();
        int n = op.length;
        for(int i=0;i<n;i++){
            if(op[i].equals("+")){
                int a = q.pollLast();
                int b = q.pollLast();
                q.addLast(b);
                q.addLast(a);
                q.addLast(a+b);
            }
            else if(op[i].equals("D")){
                q.addLast(q.peekLast()*2);
            }
            else if(op[i].equals("C")){
                q.pollLast();
            }
            else{
                q.addLast(Integer.parseInt(op[i]));
            }
        }
        int ans = 0;
        while(!q.isEmpty())ans+=q.pollLast();
        return ans;
    }
}