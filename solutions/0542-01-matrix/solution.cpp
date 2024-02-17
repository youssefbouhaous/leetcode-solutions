class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>v(m,vector<int>(n,1000'000'000));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto nxt=q.front();
            int i=nxt.first;
            int j=nxt.second;
            q.pop();
            vector<pair<int,int>>xy={{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
            for(auto r:xy){
                int x=r.first;
                int y=r.second;
                if(x>=0 && x<m && y>=0 && y<n){
                    if(v[i][j]+1<v[x][y]){
                        q.push({x,y});
                        v[x][y]=v[i][j]+1;
                    }
                }
            }
        }
        return v;
    }
};