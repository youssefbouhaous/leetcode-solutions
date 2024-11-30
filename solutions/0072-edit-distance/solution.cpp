class Solution {
    int dp[505][505];
    int f(int i,int j,string& a,string& b){
        if(i>=a.size() || j>=b.size()){
            //cout<<i<<" - "<<j<<endl;
            return abs((int)a.size()-i-(int)b.size()+j);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min({1+f(i+1,j,a,b),1+f(i,j+1,a,b),1-(a[i]==b[j])+f(i+1,j+1,a,b)});
    }
public:
    int minDistance(string word1, string word2) {
        for(int i=0;i<505;i++)for(int j=0;j<505;j++)dp[i][j]=-1;
        return f(0,0,word1,word2);
    }
};