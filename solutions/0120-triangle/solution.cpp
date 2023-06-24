class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            return grid[0][0];
        }
        vector<vector<int>>dp(n,vector<int>(grid[n-1].size(),0));
        dp[0][0]=grid[0][0];
        dp[1][0]=dp[0][0]+grid[1][0];
        dp[1][1]=dp[0][0]+grid[1][1];
        int m=2;
        for(int i=2;i<n;i++){
            m++;
            dp[i][0]=grid[i][0]+dp[i-1][0];
            for(int j=1;j<m-2;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
            dp[i][m-1]=grid[i][m-1]+dp[i-1][m-2];
            dp[i][m-2]=grid[i][m-2]+min(dp[i-1][m-2],dp[i-1][m-3]);
        }
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};