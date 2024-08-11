class Solution {
    int n;
    bool valid(int i,int j){
        return i>-1 && i<n && j>-1 && j<n;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=matrix[i][j];
                vector<int>pos;
                if(valid(i-1,j)){
                    pos.push_back(dp[i-1][j]);
                }
                if(valid(i-1,j-1)){
                    pos.push_back(dp[i-1][j-1]);
                }
                if(valid(i-1,j+1)){
                    pos.push_back(dp[i-1][j+1]);
                }
                if(pos.empty()){
                    continue;
                }
                else{
                    dp[i][j]=dp[i][j]+*min_element(pos.begin(),pos.end());
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};