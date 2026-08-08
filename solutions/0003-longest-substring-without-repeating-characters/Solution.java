class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> st = new HashSet<>();
        int n = s.length();
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n){
            char o = s.charAt(r);
            if(!st.contains(o)){
                r++;
                ans=Math.max(r-l,ans);
            }else{
                while(st.contains(o)){
                    st.remove(s.charAt(l++));
                }
                r++;
            }
            st.add(o);
        }
        return ans;
    }
}