class Solution {
public:
    map<int,vector<int>>adj;
    map<pair<int,int>,int>dir;
    map<int,bool>vis;
    int ans=0;
    void dfs(int x){
        for(auto y:adj[x]){
            if(vis.find(y)==vis.end()){
                if(dir[{x,y}]==-1){
                    ans++;
                }
                vis[y]=true;
                dfs(y);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& cnx) {
        for(auto x:cnx){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            dir[{x[0],x[1]}]=-1;
            dir[{x[1],x[0]}]=1;
        }
        vis[0]=true;
        dfs(0);
        return ans;
    }
    
};