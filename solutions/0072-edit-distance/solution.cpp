class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            dp[i][m]=n-i;
        }
        for(int i=0;i<m;i++){
            dp[n][i]=m-i;
        }
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]))+1;
                }
            }
        }
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return dp[0][0];
    }
};