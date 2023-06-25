class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ans=1;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int c=1;c<n;c++){
            for(int i=0;i<n-c;i++){
                if(s[i]==s[i+c]){
                    dp[i][i+c]=2+dp[i+1][i+c-1];
                }
                else{
                    dp[i][i+c]=max(dp[i][i+c-1],dp[i+1][i+c]);
                }
            }
        }/*
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][n-1];
    }
};