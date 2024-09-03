class Solution {
    int dp[10005];
    int f(int n){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return dp[n]=0;
        int ans=n;
        for(int i=1;i*i<=n;i++) ans=min(ans,1+f(n-i*i));
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        for(int i=0;i<10005;i++) dp[i]=-1;
        return f(n);
    }
};