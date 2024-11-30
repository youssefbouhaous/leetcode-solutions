class Solution {
    int dp[105][105][205];
    bool f(int i,int j,int l,string& s1, string& s2, string& s3){
        if(dp[i][j][l]!=-1)return dp[i][j][l];
        if(i>=s1.size() && j>=s2.size() && l>=s3.size()){
            return dp[i][j][l]=true;
        }
        if(i>=s1.size()){
            if(s2[j]!=s3[l]) return dp[i][j][l]=false;
            return dp[i][j][l]=f(i,j+1,l+1,s1,s2,s3);
        }
        else if(j>=s2.size()){
            if(s1[i]!=s3[l]) return dp[i][j][l]=false;
            return dp[i][j][l]=f(i+1,j,l+1,s1,s2,s3);
        }
        else{
            if(s1[i]==s3[l] && s2[j]==s3[l])
            return dp[i][j][l]=f(i+1,j,l+1,s1,s2,s3)||f(i,j+1,l+1,s1,s2,s3);
            else if(s1[i]==s3[l]) return dp[i][j][l]=f(i+1,j,l+1,s1,s2,s3);
            else if(s2[j]==s3[l]) return dp[i][j][l]=f(i,j+1,l+1,s1,s2,s3);
            return dp[i][j][l]=false;
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                for(int l=0;l<205;l++)
                    dp[i][j][l]=-1;
        return f(0,0,0,s1,s2,s3);
    }
};