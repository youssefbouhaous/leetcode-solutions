class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
        int n = strs.length;
        for(int i=0;i<n;i++){
            char[] arr = strs[i].toCharArray();
            Arrays.sort(arr);
            String s = new String(arr);
            if(mp.get(s)==null){
                mp.put(s,new ArrayList<>());
            }
            mp.get(s).add(strs[i]);
        }
        List<List<String>> ans = new ArrayList<>();
        for(String s : mp.keySet()){
            ans.add(mp.get(s));
        }
        return ans;
    }
}