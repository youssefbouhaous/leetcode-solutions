class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[n][m];
        dp[0][0]=0;
        if(matrix[0][0]=='1'){
            dp[0][0]=1;
            ans=1;
        }
        for(int i=1;i<n;i++){
            dp[i][0]=0;
            if(matrix[i][0]!='0'){
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int i=1;i<m;i++){
            dp[0][i]=0;
            if(matrix[0][i]!='0'){
                dp[0][i]=1;
                ans=1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int tmp=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                if(matrix[i][j]!='0'){
                    dp[i][j]=tmp+1;
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }    
        }
        return ans*ans;
    }
};