class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans=0;
        vector<int>c;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            sort(grid[i].rbegin(),grid[i].rend());
            
            for(int j=0;j<limits[i];j++){
                c.push_back(grid[i][j]);
            }
        }
        sort(c.rbegin(),c.rend());
        for(int i=0;i<c.size() && i<k;i++){
            ans=ans+(long long)c[i];
        }
        return ans;
    }
};