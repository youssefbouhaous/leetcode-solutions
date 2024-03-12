class Solution {
    public int maxProfit(int[] p) {
        int ans=0;
        int mn=p[0];
        int mx=p[0];
        for(int i=1;i<p.length;i++){
            if(mn>p[i]){
                mn=p[i];
                mx=p[i];
            }
            if(mx<p[i]){
                mx=p[i];
            }
            ans=Math.max(ans,mx-mn);
        }
        return ans;
    }
}