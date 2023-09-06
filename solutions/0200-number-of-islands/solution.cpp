class Solution {
public:
    int m,n;
    map<pair<int,int>,bool>v;
    bool valid(int i,int j){
        return 0<=i && i<m && 0<=j && j<n;
    }
    void bfs(int i,int j,vector<vector<char>>& grid){
        if(valid(i,j) && v[{i,j}]!=true && grid[i][j]=='1'){
            v[{i,j}]=true;
            bfs(i+1,j,grid);
            bfs(i-1,j,grid);
            bfs(i,j+1,grid);
            bfs(i,j-1,grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        v.clear();
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[{i,j}]!=true && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};