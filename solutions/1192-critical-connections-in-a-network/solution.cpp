class Solution {
    void IS_BRIDGE(int v,int to); 
int n; // number of nodes
unordered_map<int,vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
int timer;
vector<vector<int>>ans;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                ans.push_back({v, to});
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int nn, vector<vector<int>>& c) {
        n=nn;
        timer = 0;
        for(auto x:c){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i);
        }
        return ans;
    }
};