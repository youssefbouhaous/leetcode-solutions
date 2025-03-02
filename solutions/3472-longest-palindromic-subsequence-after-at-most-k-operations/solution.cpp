class Solution {
public:
    int dp[205][205][205];
    int n;
    string s;
    int f(int i, int j, int k){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int ans=max(f(i+1,j,k),f(i,j-1,k));
        int c=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(c<=k)ans=max(ans,2+f(i+1,j-1,k-c));
        dp[i][j][k]=ans;
        return ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        this->s = s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n-1, k);
    }
};
