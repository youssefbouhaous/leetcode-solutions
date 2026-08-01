class Solution {
    int n;
    int m;
    boolean[][] vis;
    char[][] grid;
    boolean valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void dfs(int i,int j){
        if(!valid(i,j) || vis[i][j])return;
        vis[i][j]=true;
        if(grid[i][j]=='1'){
            dfs(i+1,j);
            dfs(i,j+1);
            dfs(i-1,j);
            dfs(i,j-1);
        }
    }
    public int numIslands(char[][] grid) {
        int ans = 0;
        this.grid = grid;
        n = grid.length;
        m = grid[0].length;
        vis = new boolean[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==false){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
}