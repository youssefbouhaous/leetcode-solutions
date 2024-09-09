class Solution {
public:
    int numTrees(int n) {
        int dp[20];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=0;j<i;j++){
                dp[i]+=dp[i-j-1]*dp[j];
            }
        }
        return dp[n];
    }
};