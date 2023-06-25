class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0]-'0';
        }
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!='0'){
                int a=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                dp[i][j]=max(a,matrix[i][j]-'0');
                if(a>0){
                    dp[i][j]++;
                }
                }
            }
        }/*
        for(auto x:dp){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }*/
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,*max_element(dp[i].begin(),dp[i].end()));
        }
        return ans*ans;
    }
};