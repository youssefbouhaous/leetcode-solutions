class Solution {
public:
    int n,m;
    map<pair<int,int>,bool>v;
    bool flag=0;
    bool border(int i,int j){
        return i==0 || i==n-1 || j==0 || j==m-1;
    }
    bool valid(int i,int j){
        return 0<=i && i<n && 0<=j && j<m;
    }
    void dfs(int i,int j,vector<vector<int>>& grid){
        v[{i,j}]=true;
        if(border(i,j)){
            flag=1;
        }
        if(valid(i-1,j) && grid[i-1][j]==0 && v[{i-1,j}]!=true){
            dfs(i-1,j,grid);
        }
        if(valid(i+1,j) && grid[i+1][j]==0 && v[{i+1,j}]!=true){
            dfs(i+1,j,grid);
        }
        if(valid(i,j-1) && grid[i][j-1]==0 && v[{i,j-1}]!=true){
            dfs(i,j-1,grid);
        }
        if(valid(i,j+1) && grid[i][j+1]==0 && v[{i,j+1}]!=true){
            dfs(i,j+1,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && v[{i,j}]!=true){
                    flag=0;
                    dfs(i,j,grid);
                    if(flag==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};