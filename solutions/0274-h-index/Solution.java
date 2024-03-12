class Solution {
    public int hIndex(int[] c) {
        Arrays.sort(c);
        int n=c.length;
        int ans=0;
        int mx=c[n-1];
        for(int i=0;i<=mx;i++){
            int cc=0;
            for(int j=0;j<n;j++){
                if(c[j]>=i){
                    cc++;
                }
            }
            if(cc>=i){
                ans=Math.max(ans,i);
            }
        }
        return ans;
    }
}