class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> st = new HashSet<>();
        int l=0;
        int r=0;
        int n=s.length();
        int ans=0;
        while(r<n){
            char o= s.charAt(r);
            char tmp= s.charAt(r);
            while(st.contains(tmp)){
                st.remove(tmp);
                tmp=s.charAt(l++);
            }
            st.add(o);
            ans=Math.max(ans,r-l+1);
            r++;
        }
        return ans;
    }
}