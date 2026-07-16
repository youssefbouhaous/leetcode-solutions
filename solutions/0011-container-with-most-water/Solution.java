class Solution {
    public int maxArea(int[] h) {
        int l = 0;
        int r = h.length-1;
        int ans = r*Math.min(h[0],h[r]);

        while(l<r){
            //System.out.println(l+" "+r + " l"+h[l]+" r"+h[r]+" ans:"+ans);
            int a = (r-l-1)*Math.min(h[l],h[r-1]);
            int b = (r-l-1)*Math.min(h[l+1],h[r]);
            if(h[r]>h[l])l++;
            else r--;
            ans = Math.max(ans,Math.max(a,b));
        }
        return ans;
    }
}