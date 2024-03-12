class Solution {
    public int maxProfit(int[] p) {
        int ans=0;
        int mx=p[0];
        int mn=p[0];
        for(int i=0;i<p.length;i++){
            if(p[i]<mn || p[i]<mx){
                ans+=mx-mn;
                mx=p[i];
                mn=p[i];
            }
            if(p[i]>mx){
                mx=p[i];
            }
        }
        ans+=mx-mn;
        return ans;
    }
}