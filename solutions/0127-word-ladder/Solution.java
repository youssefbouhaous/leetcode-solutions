class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String,List<String>> mp = new HashMap<>();
        int n = beginWord.length();
        for(String s:wordList){
            StringBuilder t = new StringBuilder(s);
            for(int i=0;i<n;i++){
                char o = t.charAt(i);
                t.setCharAt(i,'*');
                String r = t.toString();
                mp.putIfAbsent(r,new ArrayList<>());
                mp.get(r).add(s);
                t.setCharAt(i,o);
            }
        }   
        Set<String> vis = new HashSet<>();
        record P(String a,Integer b){}
        Deque<P> q = new ArrayDeque<>();
        q.addLast(new P(beginWord,1));
        while(!q.isEmpty()){
            P next = q.pollFirst();
            String cur = next.a();
            Integer d = next.b();
            if(cur.equals(endWord))return d;
            if(vis.contains(cur))continue;
            vis.add(cur);
            StringBuilder t = new StringBuilder(cur);
            for(int i=0;i<n;i++){
                char o = t.charAt(i);
                t.setCharAt(i,'*');
                String r = t.toString();
                if(mp.get(r)!=null){
                    for(String x:mp.get(r)){
                        q.addLast(new P(x,d+1));
                    }
                }
                t.setCharAt(i,o);
            }
        }
        return 0;
    }
}