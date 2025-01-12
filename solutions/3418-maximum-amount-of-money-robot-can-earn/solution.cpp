class Solution {
    int n,m;
    long long dp[505][505][3];
    long long d[505][505];
    
    /*
    int f(int i, int j, int k, vector<vector<int>>& g) {
        if (i >= n || j >= m) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int result;

        if (g[i][j] < 0 && k < 2) {
            int neu = max(f(i + 1, j, k + 1, g), f(i, j + 1, k + 1, g));
            int dn = g[i][j] + max(f(i + 1, j, k, g), f(i, j + 1, k, g));
            result = max(neu, dn);
        } else {
            result = g[i][j] + max(f(i + 1, j, k, g), f(i, j + 1, k, g));
        }

        dp[i][j][k] = result;
        return result;
    }*/
public:
    int maximumAmount(vector<vector<int>>& g) {
    int n=g.size();
    int m=g[0].size();
    
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
        dp[i][j][0]=INT_MIN;
        dp[i][j][1]=INT_MIN;
        dp[i][j][2]=INT_MIN;
        d[i][j]=INT_MIN;
    }
    if (g[0][0] >= 0) {
        dp[0][0][0]=g[0][0];
        dp[0][0][1]=g[0][0];
        dp[0][0][2]=g[0][0];
    } else {
        dp[0][0][0]=g[0][0];
        dp[0][0][1]=0;
        dp[0][0][2]=INT_MIN;
    }
    d[0][0]=max(g[0][0],0);
    for(int j=1;j<m;j++) {
        if (g[0][j]>=0) {
            dp[0][j][0]=dp[0][j-1][0]+g[0][j];
            dp[0][j][1]=dp[0][j-1][1]+g[0][j];
            dp[0][j][2]=dp[0][j-1][2]+g[0][j];
        } else {
            dp[0][j][0]=dp[0][j-1][0]+g[0][j];
            dp[0][j][1]=max(dp[0][j-1][1]+g[0][j],dp[0][j-1][0]);
            dp[0][j][2]=max(dp[0][j-1][2]+g[0][j],dp[0][j-1][1]);
        }
        d[0][j]=max({dp[0][j][0],dp[0][j][1],dp[0][j][2]});
    }
    for(int i=1;i<n;i++) {
        if(g[i][0]>=0) {
            dp[i][0][0]=dp[i-1][0][0]+g[i][0];
            dp[i][0][1]=dp[i-1][0][1]+g[i][0];
            dp[i][0][2]=dp[i-1][0][2] + g[i][0];
        } else {
            dp[i][0][0]=dp[i-1][0][0] + g[i][0];
            dp[i][0][1]=max(dp[i-1][0][1] + g[i][0],dp[i-1][0][0]);
            dp[i][0][2]=max(dp[i-1][0][2] + g[i][0],dp[i-1][0][1]);
        }
        d[i][0]=max({dp[i][0][0],dp[i][0][1], dp[i][0][2]});
    }

    for (int i = 1; i < n; i++) {
        for (int j=1;j<m;j++) {
            if (g[i][j] >= 0) {
                dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+g[i][j];
                dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1]) + g[i][j];
                dp[i][j][2]=max(dp[i-1][j][2],dp[i][j-1][2]) + g[i][j];
            } else {
                dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0]) + g[i][j];
                dp[i][j][1]=max({dp[i-1][j][1]+g[i][j],dp[i][j-1][1]+g[i][j],dp[i-1][j][0],dp[i][j-1][0]});
                dp[i][j][2]=max({dp[i-1][j][2]+g[i][j],dp[i][j-1][2]+g[i][j],dp[i-1][j][1],dp[i][j-1][1]});
            }
            d[i][j]=max({dp[i][j][0], dp[i][j][1],dp[i][j][2]});
        }
    }

    return d[n-1][m-1];
}
};