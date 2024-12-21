class Solution {
    int n,m;
    long long ans=0;
    const long long mod=1e9+7;
    int dp[301][301][17];
    int k;
    bool valid(int i,int j){
        return i>-1 && i<n && j>-1 && j<m;
    }
    int dfs(int i,int j,vector<vector<int>>& grid,int s){
        if(dp[i][j][s]!=-1){
            return dp[i][j][s];
        }
        if(i==n-1 && j==m-1){
            if(s==k)
            return dp[i][j][k]=1;
        }
        if(valid(i+1,j) && valid(i,j+1)){
            dp[i][j][s]=(dfs(i+1,j,grid,s^grid[i+1][j])+dfs(i,j+1,grid,s^grid[i][j+1]))%mod;
        }
        else if(valid(i+1,j)){dp[i][j][s]=dfs(i+1,j,grid,s^grid[i+1][j])%mod;}
        else if(valid(i,j+1)){dp[i][j][s]=dfs(i,j+1,grid,s^grid[i][j+1])%mod;}
        else{dp[i][j][s]=0;}
        return dp[i][j][s];
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int kk) {
        k=kk;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int l=0;l<17;l++)dp[i][j][l]=-1;
        dfs(0,0,grid,grid[0][0]);
        return dp[0][0][grid[0][0]];
    }
};