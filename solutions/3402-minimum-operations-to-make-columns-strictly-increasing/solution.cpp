class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[j][i]<=grid[j-1][i]){
                    int o=grid[j-1][i]-grid[j][i]+1;
                    ans+=o;
                    grid[j][i]=grid[j-1][i]+1;
                }
            }
        }
        return ans;
    }
};