class Solution {
    int n;
    unordered_map<int,vector<int>> adj;
    vector<char> color;
    vector<int> parent;

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
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        n=numCourses;
        color.assign(n, 0);
        parent.assign(n, -1);
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
        }
        for(auto x:p){
            if(dfs(x[0])){
                return false;
            }
        }
        return true;
    }
};