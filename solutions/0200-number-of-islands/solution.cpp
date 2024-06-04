class Solution {
public:
    map<pair<int,int>,bool>visited;
    int n,m;
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(!valid(i,j) || visited[{i,j}] || grid[i][j]!='1'){
            return;
        }
        visited[{i,j}]=true;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[{i,j}] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};