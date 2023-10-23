class Solution {
public:
    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            dp[i][m]=n-i;
        }
        for(int j=0;j<m;j++){
            dp[n][j]=m-j;
        }
        
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                if(a[i]==b[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    dp[i][j]=min({dp[i+1][j+1],dp[i][j+1],dp[i+1][j]})+1;
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