class Solution {
    record Pair(String a,Integer b){}
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> map = new HashMap<>();
        int n = words.length;
        for(int i=0;i<n;i++){
            map.put(words[i],map.getOrDefault(words[i],0)+1);
        }
        List<Pair> list = new ArrayList<>();
        for(String s : map.keySet()){
            list.add(new Pair(s,map.get(s)));
        }
        list.sort((a,b)->{
            if(a.b.equals(b.b)){
                return a.a.compareTo(b.a);
            }
            return b.b.compareTo(a.b);
        });
        List<String> ans = new ArrayList<>();
        for(int i =0 ;i<list.size() && k>0;i++,k--){
            ans.add(list.get(i).a);
        }
        return ans;
    }
}