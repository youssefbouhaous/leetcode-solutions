class Solution {
    int dp[505][505];
    int f(int i,int j,string&s){
        if(i>=j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=f(i+1,j-1,s);
        return dp[i][j]=1+min(f(i+1,j,s),f(i,j-1,s));
    }
    public:
    int minInsertions(string s) {
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                dp[i][j]=-1;
            }
        }
            return f(0,s.size()-1,s);
    }
};