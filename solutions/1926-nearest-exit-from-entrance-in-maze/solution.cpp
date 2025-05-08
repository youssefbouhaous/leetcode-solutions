class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int i=e[0];
        int j=e[1];
        n=maze.size();
        m=maze[0].size();
        bool found=false;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>d(n,vector<int>(m));
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            vector<pair<int,int>>xy={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto r:xy){
                pair<int,int>o={it.first+r.first,it.second+r.second};
                if(!isValid(o.first,o.second))continue;
                if(!vis[o.first][o.second] && maze[o.first][o.second]=='.'){
                    vis[o.first][o.second]=true;
                    d[o.first][o.second]=d[it.first][it.second]+1;
                    if(o.second==m-1 || o.first==n-1 || o.second==0 || o.first==0){
                        return d[o.first][o.second];
                    }
                    q.push(o);
                }
            }
        }
        return -1;
    }
};