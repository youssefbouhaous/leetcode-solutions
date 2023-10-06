class Solution {
public:

    int n,m;
    int c=0;
    bool valid(int i,int j){
        return 0<=i && i<n && 0<=j && j<m;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&v){
        if(valid(i,j) && grid[i][j]==1 && v[i][j]!=true){
            c++;
            v[i][j]=true;
            dfs(i+1,j,grid,v);
            dfs(i-1,j,grid,v);
            dfs(i,j+1,grid,v);
            dfs(i,j-1,grid,v);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>v(n,vector<bool>(m));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==false && grid[i][j]==1){
                    c=0;
                    dfs(i,j,grid,v);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};