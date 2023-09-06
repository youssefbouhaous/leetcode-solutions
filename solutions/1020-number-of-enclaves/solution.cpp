class Solution {
public:
    map<pair<int,int>,bool>v;
    int m,n;
    bool valid(int i,int j){
        return 0<=i && i<m && 0<=j && j<n;
    }
    void bfs(int i,int j,vector<vector<int>>& grid){
        if(valid(i,j) && v[{i,j}]!=true && grid[i][j]==1){
            v[{i,j}]=true;
            bfs(i+1,j,grid);
            bfs(i-1,j,grid);
            bfs(i,j+1,grid);
            bfs(i,j-1,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        m=grid.size();
        n=grid[0].size();
        v.clear();
        for(int i=0;i<m;i++){
            if(v[{i,0}]!=true && grid[i][0]==1) bfs(i,0,grid);
            if(v[{i,n-1}]!=true && grid[i][n-1]==1) bfs(i,n-1,grid);
        }
        for(int i=0;i<n;i++){
            if(v[{0,i}]!=true && grid[0][i]==1) bfs(0,i,grid);
            if(v[{m-1,i}]!=true && grid[m-1][i]==1) bfs(m-1,i,grid);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && v[{i,j}]!=true) ans++;
            }
        }
        return ans;
    }
};