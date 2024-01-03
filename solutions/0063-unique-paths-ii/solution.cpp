class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size();
        int m=o[0].size();
        if(n==1 && m==1){
            return 1-o[0][0];
        }
        int dp[n][m];
        dp[0][0]=1-o[0][0];
        for(int i=1;i<n;i++){
            if(o[i][0]!=1){
                dp[i][0]=dp[i-1][0];
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int i=1;i<m;i++){
            if(o[0][i]!=1){
                dp[0][i]=dp[0][i-1];
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(o[i][j]!=1){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};