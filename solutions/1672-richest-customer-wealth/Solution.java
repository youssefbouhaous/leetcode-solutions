class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = 0;
        int n = accounts.length;
        for(int i=0;i<n;i++){
            int t = Arrays.stream(accounts[i]).sum();
            ans = Math.max(ans,t);
        }
        return ans;
    }
}