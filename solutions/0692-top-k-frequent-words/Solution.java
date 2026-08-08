class Solution {
    public record Pair(String s,Integer cnt){}
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> mp = new HashMap<>();
        for(String s:words){
            mp.put(s,mp.getOrDefault(s,0)+1);
        }
        PriorityQueue<Pair> q = new PriorityQueue<>((a,b)->{
            if(a.cnt==b.cnt)return a.s.compareTo(b.s);
            return b.cnt-a.cnt;
        });
        for(String s:mp.keySet()){
            q.add(new Pair(s,mp.get(s)));
        }
        List<String> ans = new ArrayList<>();
        while(!q.isEmpty()){
            ans.add(q.poll().s);
            k--;
            if(k<1)break;
        }
        return ans;
    }
}