class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>a(n);
        vector<int>b(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=min(rowSum[i]-a[i],colSum[j]-b[j]);
                a[i]+=ans[i][j];
                b[j]+=ans[i][j];
            }
        }
        return ans;
    }
};