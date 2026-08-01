class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        List<String> list = Arrays.asList(arr);
        Collections.reverse(list);
        StringBuilder ans = new StringBuilder();
        for(String ss:list){
            if(ss.isEmpty())continue;
            ans.append(ss.trim()+" ");
        }
        return ans.toString().trim();
    }
}