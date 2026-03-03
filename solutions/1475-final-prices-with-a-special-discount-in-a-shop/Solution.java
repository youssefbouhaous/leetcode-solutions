class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] ans = prices.clone();
        for(int i=n-2;i>-1;i--){
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    ans[i] -= prices[j];
                    break;
                }
            }
        }
        return ans;
    }
}