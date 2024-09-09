class Solution {
    int dp[367][10001];
    int f(int i,int m,vector<int>& d, vector<int>& c){
        if(i>=d.size()){
            return dp[i][m]=0;
        }
        if(dp[i][m]!=-1)return dp[i][m];
        if(d[i]<=m)
        return dp[i][m]=min({f(i+1,m,d,c),c[0]+f(i+1,m+1,d,c),c[1]+f(i+1,m+7,d,c),c[2]+f(i+1,m+30,d,c)});
        return dp[i][m]=min({c[0]+f(i+1,d[i],d,c),c[1]+f(i+1,d[i]+6,d,c),c[2]+f(i+1,d[i]+29,d,c)});;
    }
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        for(int i=0;i<367;i++)for(int j=0;j<10001;j++)dp[i][j]=-1;
        return f(0,0,d,c);
    }
};