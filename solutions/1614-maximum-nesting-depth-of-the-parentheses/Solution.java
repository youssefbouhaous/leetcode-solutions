class Solution {
    public int maxDepth(String s) {
        int ans = 0;
        int c = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o=='('){
                c++;
            }else if(o==')')c--;
            ans = Math.max(ans,c);
        }
        return ans;
    }
}