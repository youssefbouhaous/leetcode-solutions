class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> st = new HashSet<>();
        int n = s.length();
        int l=0;
        int r=0;
        int ans =0;
        while(r<n){
            char cur = s.charAt(r);
            if(!st.contains(cur)){
                ans=Math.max(ans,r-l+1);
                r++;
                st.add(cur);
            }else{
                cur = s.charAt(l);
                while(st.contains(s.charAt(r))){
                    st.remove(cur);
                    if(l>=n)break;
                    cur=s.charAt(++l);
                }
                if(l>=r)l=r;
                st.add(s.charAt(r));r++;
            }
            ans=Math.max(ans,r-l);
        }
        return ans;
    }
}