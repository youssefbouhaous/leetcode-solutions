class Solution {
    Map<String,List<String>> mp = new HashMap<>();
    record P(String a,Integer b){}
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> end=new HashSet<>();
        StringBuilder t = new StringBuilder(endGene);
            for(int i=0;i<8;i++){
                char o = t.charAt(i);
                t.setCharAt(i,'*');
                end.add(t.toString());
                t.setCharAt(i,o);
            }
        for(String s:bank){
            t = new StringBuilder(s);
            for(int i=0;i<8;i++){
                char o = t.charAt(i);
                t.setCharAt(i,'*');
                String r = t.toString();
                mp.putIfAbsent(r,new ArrayList<>());
                mp.get(r).add(s);
                t.setCharAt(i,o);
            }
        }
        Set<String> vis = new HashSet<>();
        Deque<P> q = new ArrayDeque<>();
        q.addLast(new P(startGene,0));
        while(!q.isEmpty()){
            P next = q.pollFirst();
            if(endGene.equals(next.a()))return next.b();
            if(vis.contains(next.a()))continue;
            vis.add(next.a());
            t = new StringBuilder(next.a());
            for(int i=0;i<8;i++){
                char o = t.charAt(i);
                t.setCharAt(i,'*');
                String r = t.toString();
                if(mp.containsKey(r))
                for(String x:mp.get(r)){
                    q.addLast(new P(x,next.b()+1));
                }
                t.setCharAt(i,o);
            }
        }
        return -1;
    }
}