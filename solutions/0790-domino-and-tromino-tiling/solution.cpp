class Solution {
public:
    int numTilings(int n) {
        long long int dp[1002][4];
        int m=1'000'000'007;
        dp[1][3]=1;
        dp[2][3]=2;
        dp[3][1]=2;
        dp[3][2]=2;
        dp[3][3]=5;
        dp[3][0]=2;
        for(int i=4;i<=n;i++){
            dp[i][0]=dp[i-1][3]%m;
            dp[i][1]=(dp[i-1][2]%m+dp[i-1][0]%m)%m;
            dp[i][2]=(dp[i-1][1]%m+dp[i-1][0]%m)%m;
            dp[i][3]=(dp[i-1][3]%m+dp[i-1][1]%m+dp[i-1][2]%m+dp[i-1][0]%m)%m;
        }
        return (int)dp[n][3];
    }
};