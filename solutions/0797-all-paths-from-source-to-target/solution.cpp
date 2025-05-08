class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>>adj;
    vector<int>path;
    vector<bool>vis;
    int n;
    void dfs(int x,vector<vector<int>>& adj){
        path.push_back(x);
        if(x==n-1){
            ans.push_back(path);
            return;
        }
        for(auto y:adj[x]){
            dfs(y,adj);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        n=adj.size();
        vis.resize(n+1,false);
        vis[0]=true;
        dfs(0,adj);
        return ans;
    }
};