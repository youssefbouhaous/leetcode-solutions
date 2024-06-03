class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        dp.push_back(triangle[0]);
        int n=triangle.size();
        if(n>1){
            vector<int>tmp={triangle[1][0]+triangle[0][0],triangle[1][1]+triangle[0][0]};
            dp.push_back(tmp);
        }
        for(int i=2;i<n;i++){
            vector<int>tmp;
            tmp.push_back(dp[i-1][0]+triangle[i][0]);
            for(int j=1;j<i;j++){
                tmp.push_back(triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]));
            }
            tmp.push_back(dp[i-1][i-1]+triangle[i][i]);
            dp.push_back(tmp);
        }
        int m=dp[n-1][0];
        for(auto x:dp[n-1]){
            m=min(m,x);
        }
        
        return m;
    }
};