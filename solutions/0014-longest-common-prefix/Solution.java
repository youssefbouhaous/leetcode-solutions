class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder();
        int n = strs.length;
        int mx = Arrays.stream(strs).mapToInt(s->s.length()).min().getAsInt();
        System.out.println(mx); 
        for(int i =0;i<mx;i++){
            boolean f = true;
            char t = strs[0].charAt(i);
            for(int j=0;j<n;j++){
                if(strs[j].charAt(i)!=t){
                    f=false;break;
                }
            }
            if(!f)break;
            ans.append(t);
        }
        return ans.toString();
    }
}