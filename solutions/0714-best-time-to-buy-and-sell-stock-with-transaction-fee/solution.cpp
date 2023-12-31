class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        int dp[50'005][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][1]+prices[i]-fee,dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};