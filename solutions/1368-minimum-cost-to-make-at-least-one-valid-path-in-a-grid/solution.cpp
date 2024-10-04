class Solution {
    int n,m;
    bool valide(int i,int j){
        return i<n && i>-1 && j>-1 && j<m;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int INF=1e9;
        map<pair<int,int>,int>mp;
        mp[{0,1}]=1;
        mp[{0,-1}]=2;
        mp[{1,0}]=3;
        mp[{-1,0}]=4;
        vector<vector<int>>d(n,vector<int>(m,INF));
        d[0][0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front();
            int i=it.first;
            int j=it.second;
            q.pop();
                vector<pair<int,int>>xy={{1,0},{0,1},{-1,0},{0,-1}};
                for(auto r:xy){
                    int x=r.first;
                    int y=r.second;
                    if(valide(i+x,j+y)){
                        if(mp[{x,y}]==grid[i][j] && d[i+x][j+y]>d[i][j]){
                            d[i+x][j+y]=min(d[i+x][j+y],d[i][j]);
                            q.push({i+x,j+y});
                        }
                        else if(d[i+x][j+y]>d[i][j]+1){
                            d[i+x][j+y]=min(d[i+x][j+y],d[i][j]+1);
                            q.push({i+x,j+y});
                        }
                    }
                }
        }
        return d[n-1][m-1];
    }
};