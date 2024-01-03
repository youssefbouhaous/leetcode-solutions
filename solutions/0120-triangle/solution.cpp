class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        if(n==1){
            return t[0][0];
        }
        int dp[n][n];
        dp[0][0]=t[0][0];
        dp[1][0]=dp[0][0]+t[1][0];
        dp[1][1]=dp[0][0]+t[1][1];
        for(int i=2;i<n;i++){
            dp[i][0]=dp[i-1][0]+t[i][0];
            for(int j=1;j<i;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+t[i][j];
            }
            dp[i][i]=dp[i-1][i-1]+t[i][i];
        }
        int ans=dp[n-1][n-1];
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};