class Solution {
public:
    int dis(int i,int j,string& a,string& b,vector<vector<int>>&dp){
        if(i==a.size() || j==b.size()){
            return max(a.size()-i,b.size()-j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]) return dp[i][j]=dis(i+1,j+1,a,b,dp);
        else{
            return dp[i][j]=min({1+dis(i+1,j,a,b,dp),1+dis(i,j+1,a,b,dp),1+dis(i+1,j+1,a,b,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n==0 || m==0){
            return max(n,m);
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dis(0,0,word1,word2,dp);
        return dp[0][0];
    }
};