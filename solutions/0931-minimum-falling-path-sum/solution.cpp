class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        if(m>1){
        for(int i=1;i<n;i++){
            dp[i][0]=matrix[i][0]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][m-1]=matrix[i][m-1]+min(dp[i-1][m-1],dp[i-1][m-2]);
            for(int j=1;j<m-1;j++){
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
        }
        else{
            for(int i=1;i<n;i++){
                dp[i][0]=matrix[i][0]+dp[i-1][0];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};