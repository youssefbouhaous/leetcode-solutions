class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>v(n,vector<int>(m,1e9));
        if(grid[0][0]==1){
            return -1;
        }
        v[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto nxt=q.front();
            int i=nxt.first;
            int j=nxt.second;
            q.pop();
            vector<pair<int,int>>xy={{i+1,j},{i-1,j},{i,j+1},{i,j-1},{i+1,j+1},{i+1,j-1},{i-1,j+1},{i-1,j-1}};
            for(auto r:xy){
                int x=r.first;
                int y=r.second;
                if(x<n && x>-1 && y>-1 && y<m && grid[x][y]==0 && v[i][j]+1<v[x][y]){
                    v[x][y]=v[i][j]+1;
                    q.push({x,y});
                }
            }
        }
        if(v[n-1][m-1]==1e9){
            return -1;
        }
        return v[n-1][m-1];
    }
};