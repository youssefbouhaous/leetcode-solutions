class Solution {
public:
    map<int,vector<int>>adj;
    map<int,bool>v;
    map<int,char> color;
    map<int,int> parent;

    bool dfs(int v) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }    
        for(int i=0;i<n;i++){
            v.clear();
            if(dfs(i)){
                return false;
            }
        }
        return true;
    }
};