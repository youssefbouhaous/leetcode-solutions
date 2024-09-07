class Solution {
    long long int dp[1001][4];
    const int mod=1000000007;
public:
    int numTilings(int n) {
        if(n<2) return n;
        dp[1][0]=1;
        dp[1][3]=1;
        dp[1][1]=0;
        dp[1][2]=0;
        for(int i=2;i<=n;i++){
            dp[i][0]=dp[i-1][3];
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2]=(dp[i-1][0]+dp[i-1][1])%mod;
            dp[i][3]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
        }
        return dp[n][3];
    }
};