class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        Map<String,ArrayList<String>> mp = new HashMap<>();
        for(String x:strs){
            char[] t = x.toCharArray();
            Arrays.sort(t);
            String tmp = new String(t);
            mp.putIfAbsent(tmp,new ArrayList<>());
            mp.get(tmp).add(x);
        }
        for(String x:mp.keySet()){
            List<String> tmp = new ArrayList<>();
            for(String c:mp.get(x)){
                tmp.add(c);
            }
            ans.add(tmp);
        }
        return ans;
    }
}