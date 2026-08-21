class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        Map<String,Integer> st = new HashMap<>();
        int mx = 0;
        for(int i=0;i<n;i++){
            StringBuilder tmp = new StringBuilder();
            int[] cnt = new int[26];
            int uni = 0;
            for(int j=i;j<Math.min(i+maxSize,n);j++){
                tmp.append(s.charAt(j));
                cnt[s.charAt(j)-'a']++;
                if(cnt[s.charAt(j)-'a']==1)uni++;
                if(tmp.length()>=minSize && uni<=maxLetters){
                    String ts = tmp.toString();
                    st.put(ts,st.getOrDefault(ts,0)+1);
                    mx=Math.max(mx,st.get(ts));
                }
            }
        }
        return mx;
    }
}