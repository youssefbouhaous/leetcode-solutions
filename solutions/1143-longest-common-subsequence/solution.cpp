class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        int dp[n][m];
        if(a[0]==b[0]){
            dp[0][0]=1;
        }
        else{
            dp[0][0]=0;
        }
        for(int i=1;i<n;i++){
            if(a[i]==b[0]){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=max(dp[i-1][0],0);
            }
        }
        for(int i=1;i<m;i++){
            if(a[0]==b[i]){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=max(dp[0][i-1],0);
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(a[i]==b[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n-1][m-1];
    }
};