class Solution {
    public int[] asteroidCollision(int[] a) {
        int n = a.length;
        Deque<Integer> q = new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(q.isEmpty()){
                q.add(a[i]);continue;
            }
            int p = q.peekLast();
            if(p<0){
                q.add(a[i]);
            }
            else if(p>0 && a[i]>0){
                q.add(a[i]);
            }else{
                boolean f = false;
                while(!q.isEmpty() && a[i]<0 && q.peekLast()>0){
                    if(Math.abs(a[i])==q.peekLast()){
                        q.pollLast();break;
                    }
                    else if(q.peekLast()>Math.abs(a[i]))break;
                    else{
                    
                        q.pollLast();
                       if(q.isEmpty()){
                        q.add(a[i]);break;
                       }if(q.peekLast()<0){
                            q.add(a[i]);break;
                        } 
                    }
                }
            }
        }
        int ans[] = new int[q.size()];
        int id = 0;
        while(!q.isEmpty()){
            ans[id++]=q.pollFirst();
        }
        //Collections.reverse(Arrays.asList(ans));
        return ans; 
    }
}