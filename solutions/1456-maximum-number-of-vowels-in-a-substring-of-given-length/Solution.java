class Solution {
    public int maxVowels(String s, int k) {
        int l = 0;
        int r = k-1;
        HashSet<Character> st = new HashSet<>(List.of('a','e','i','o','u'));
        int cur = 0;
        int n = s.length();
        int ans = 0;
        for(int i=0;i<k;i++){
            if(st.contains(s.charAt(i))){
                cur++;
            }
        }
        ans = cur;
        while(r<n-1){
            if(st.contains(s.charAt(l))){
                cur--;
            }
            if(st.contains(s.charAt(r+1))){
                cur++;
            }
            r++;l++;
            ans = Math.max(ans,cur);
        }
        return ans;
    }
}