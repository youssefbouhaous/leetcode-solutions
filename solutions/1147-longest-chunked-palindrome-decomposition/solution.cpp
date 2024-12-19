class Solution {
    int n;
    long long p=293;
    long long mod=1e9+7;
    vector<long long>pp;
    vector<long long>h;
    int dp[1005][1005];
    string t;
    int f(int i, int j) {
    if (i > j) return 0; 
    if (i == j) return 1; 
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 1;
    for (int l = 0; l <= (j - i) / 2; l++) {
        long long cur = (h[i + l + 1] - h[i] + mod) % mod;
        long long cur2 = (h[j + 1] - h[j - l] + mod) % mod;
        cur = (h[i + l + 1] - h[i] + mod) % mod;
cur = (cur * pp[n - i - l - 1]) % mod;

cur2 = (h[j + 1] - h[j - l] + mod) % mod;
cur2 = (cur2 * pp[n - j - 1]) % mod;

        if (cur == cur2) { 
            ans = max(ans, 2 + f(i + l + 1, j - l - 1));
        }
    }
    return dp[i][j]=ans;
}

public:
    int longestDecomposition(string text) {
        n=text.size();
        t=text;
        for(int i=0;i<1005;i++)for(int j=0;j<1005;j++)dp[i][j]=-1;
        pp.assign(n+1,0);
        h.assign(n+1,0);
        pp[0]=1;
        for(int i=1;i<n;i++)pp[i]=(pp[i-1]*p)%mod;
        for(int i=0;i<n;i++)h[i+1]=(h[i]+(text[i]-'a'+1)*pp[i])%mod;
        return f(0,n-1);
    }
};