class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1){
            return matrix[0][0];
        }
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=min(dp[i-1][0],dp[i-1][1])+matrix[i][0];
            
            dp[i][n-1]=min(dp[i-1][n-1],dp[i-1][n-2])+matrix[i][n-1];
            for(int j=1;j<n-1;j++){
                dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+matrix[i][j];
            }
        }
        int ans=dp[n-1][n-1];
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};