class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return 0<=i && 0<=j && i<n && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        pair<int,int>start;
        n=grid.size();
        m=grid[0].size();
        map<pair<int,int>,bool>v;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    v[{i,j}]=true;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> next=q.front().first;
            int l=q.front().second;
            q.pop();
            int i=next.first;
            int j=next.second;
            ans=max(ans,l);
            if(valid(i+1,j) && v[{i+1,j}]!=true && grid[i+1][j]==1){
                v[{i+1,j}]=true;
                grid[i+1][j]=2;
                q.push({{i+1,j},l+1});
            }
            if(valid(i-1,j) && v[{i-1,j}]!=true && grid[i-1][j]==1){
                v[{i-1,j}]=true;
                grid[i-1][j]=2;
                q.push({{i-1,j},l+1});
            }
            if(valid(i,j+1) && v[{i,j+1}]!=true && grid[i][j+1]==1){
                v[{i,j+1}]=true;
                grid[i][j+1]=2;
                q.push({{i,j+1},l+1});
            }
            if(valid(i,j-1) && v[{i,j-1}]!=true && grid[i][j-1]==1){
                v[{i,j-1}]=true;
                grid[i][j-1]=2;
                q.push({{i,j-1},l+1});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};