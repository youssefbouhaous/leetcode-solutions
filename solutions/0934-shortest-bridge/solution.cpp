class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return 0<=i && i<n && 0<=j && j<m;
    }
    bool bond(int i,int j,vector<vector<int>>& grid){
        if(valid(i+1,j) && grid[i+1][j]==0){
            return true;
        }
        if(valid(i-1,j) && grid[i-1][j]==0){
            return true;
        }
        if(valid(i,j+1) && grid[i][j+1]==0){
            return true;
        }
        if(valid(i,j-1) && grid[i][j-1]==0){
            return true;
        }
        return false;
    }
    vector<pair<int,int>>g1;
    vector<pair<int,int>>g2;
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& v){
        if(bond(i,j,grid))
        g1.push_back({i,j});

        v[i][j]=true;
        if(valid(i+1,j) && grid[i+1][j]==1 &&  v[i+1][j]!=true){
            bfs(i+1,j,grid,v);
        }
        if(valid(i-1,j) && grid[i-1][j]==1 && v[i-1][j]!=true){
            bfs(i-1,j,grid,v);
        }
        if(valid(i,j+1) && grid[i][j+1]==1 && v[i][j+1]!=true ){
            bfs(i,j+1,grid,v);
        }
        if(valid(i,j-1) && grid[i][j-1]==1 && v[i][j-1]!=true){
            bfs(i,j-1,grid,v);
        }
        
    }
    void bfs2(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& v){
        g2.push_back({i,j});
        v[i][j]=true;
        if(valid(i+1,j) && grid[i+1][j]==1 &&  v[i+1][j]!=true ){
            bfs2(i+1,j,grid,v);
        }
        if(valid(i-1,j) && grid[i-1][j]==1 && v[i-1][j]!=true){
            bfs2(i-1,j,grid,v);
        }
        if(valid(i,j+1) && grid[i][j+1]==1 && v[i][j+1]!=true){
            bfs2(i,j+1,grid,v);
        }
        if(valid(i,j-1) && grid[i][j-1]==1 && v[i][j-1]!=true){
            bfs2(i,j-1,grid,v);
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> v(n,vector<bool>(m));
        bool f=0;
        for(int i=0;i<n && f!=1;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid,v);
                    f=1;
                    break;
                }
            }
        }
        f=0;
        for(int i=0;i<n && f!=1;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && v[i][j]==false){
                    bfs2(i,j,grid,v);
                    f=1;
                    break;
                }
            }
        }
        int ans=10002;
        for(auto x:g1){
            for(auto y:g2){
                ans=min(ans,abs(x.first-y.first)+abs(x.second-y.second)-1);
            }
        }
        cout<<g1.size()<<" "<<g2.size();
        return ans;
    }
};