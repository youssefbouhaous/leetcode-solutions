class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        string a=s;
        reverse(s.begin(),s.end());
        if(s[0]==a[0]){
            dp[0][0]=1;
        }
        else{
            dp[0][0]=0;
        }
        for(int i=1;i<n;i++){
            if(s[i]==a[0]){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int i=1;i<n;i++){
            if(s[0]==a[i]){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(s[i]==a[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[n-1][n-1];
    }
};