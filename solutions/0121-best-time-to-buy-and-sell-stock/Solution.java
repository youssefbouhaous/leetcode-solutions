class Solution {
    public int maxProfit(int[] prices) {
        int mn = Integer.MAX_VALUE;
        int mx = 0;
        int ans = 0;
        int n = prices.length;
        for(int i=0;i<n;i++){
            ans = Math.max(ans,prices[i]-mn);
            mn = Math.min(mn,prices[i]);
        }
        return ans;
    }
}