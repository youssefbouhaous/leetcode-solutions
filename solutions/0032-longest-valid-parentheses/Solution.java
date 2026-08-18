class Solution {
    public int longestValidParentheses(String s) {
        int ans=0;
        int c=0;
        int len=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char o = s.charAt(i);
            if(o=='('){
                c++;
            }else{
                c--;len++;
            }
            if(c==0){
                ans= Math.max(ans,len*2);
            }
            if(c<0){c=0;len=0;}
        }
        if(c==0)
        ans= Math.max(ans,len*2);
        c=0;
        len=0;
        for(int i=n-1;i>=0;i--){
            char o = s.charAt(i);
            if(o==')'){
                c++;
            }else {
                c--;len++;
            }
            if(c==0){
                ans = Math.max(ans,len*2);
            }
            if(c<0){c=0;len=0;}
        }
        if(c==0)ans=Math.max(ans,len*2);
        return ans;
    }
}