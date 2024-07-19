class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mx=matrix[i][j];
                int mxn=matrix[i][j];
                int mxx=matrix[i][j];
                for(int u=0;u<n;u++){
                    mxn=max(mxn,matrix[u][j]);
                }
                for(int u=0;u<m;u++){
                    mxx=min(mxx,matrix[i][u]);
                }
                if(mx==mxx && mx==mxn){
                    ans.push_back(mx);
                }
            }
        }
        return ans;
    }
};