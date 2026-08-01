class Solution {
    public String longestCommonPrefix(String[] strs) {
        int mn = Arrays.stream(strs).mapToInt(s->s.length()).min().getAsInt();
        int n = strs.length;
        StringBuilder s = new StringBuilder();
        loop1:for(int i=0;i<mn;i++){
            for(int j=0;j<n;j++){
                if(strs[j].charAt(i)!=strs[0].charAt(i)){
                    break loop1;
                }
            }
            s.append(strs[0].charAt(i));
        }
        return s.toString();
    }
}