class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n=a.size();
        int m=b.size();
        int dp[n+1][m+1];
        dp[n][m]=0;
        for(int i=m-1;i>-1;i--){
            dp[n][i]=b[i]+dp[n][i+1];
        }
        for(int i=n-1;i>-1;i--){
            dp[i][m]=a[i]+dp[i+1][m];
        }
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                if(a[i]==b[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=min({dp[i+1][j]+a[i],dp[i][j+1]+b[j],dp[i+1][j+1]+a[i]+b[j]});
                }
            }
        }
        /*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][0];
    }
};