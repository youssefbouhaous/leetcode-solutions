class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        vector<vector<int>> prefiy(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = grid[i][j]=='X' ? 1 : 0;
                if (i > 0) prefix[i][j] += prefix[i-1][j];
                if (j > 0) prefix[i][j] += prefix[i][j-1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefiy[i][j] = grid[i][j]=='Y' ? 1 : 0;
                if (i > 0) prefiy[i][j] += prefiy[i-1][j];
                if (j > 0) prefiy[i][j] += prefiy[i][j-1];
                if (i > 0 && j > 0) prefiy[i][j] -= prefiy[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<prefix[i][j]<<" "<<prefiy[i][j]<<" i:"<<i<<" j:"<<j<<endl;
                if(prefix[i][j]>=1 && prefix[i][j]==prefiy[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};