class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=m-1;j>-1;j--){
            dp[n][j]=dp[n][j+1]+s2[j];
        }
        for(int i=n-1;i>-1;i--){
            dp[i][m]=dp[i+1][m]+s1[i];
        }
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=min(s1[i]+dp[i+1][j],min(s2[j]+dp[i][j+1],s1[i]+s2[j]+dp[i+1][j+1]));
                }
            }
        }/*
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][0];
    }
};