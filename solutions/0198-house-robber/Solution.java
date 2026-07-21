class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1)return nums[0];
        int[][] dp = new int[n][2];
        dp[0][0] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        for(int i=2;i<n;i++){
            dp[i][0] = nums[i]+ dp[i-1][1];
            dp[i][1] = Math.max(dp[i-1][0],dp[i-1][1]);
        }
        return Math.max(dp[n-1][0],dp[n-1][1]);
    }
}