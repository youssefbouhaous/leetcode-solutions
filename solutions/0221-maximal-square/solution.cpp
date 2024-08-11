class Solution {
public:
    int maximalSquare(vector<vector<char>>& mx) {
        int n=mx.size();
        int m=mx[0].size();
        vector<vector<int>>matrix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=(mx[i][j]=='1') ? 1 : 0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,matrix[i][0]);
        }
        for(int j=0;j<m;j++){
            ans=max(ans,matrix[0][j]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) continue;
                if(matrix[i-1][j]>0 && matrix[i][j-1]>0 && matrix[i-1][j-1]>0){
                    matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                }
                ans=max(ans,matrix[i][j]);
            }
        }
        return ans*ans;
    }
};