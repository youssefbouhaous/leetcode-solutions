class Solution {
    int n; // number of vertices
    vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited;
    vector<int> ans;

    void dfs(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u);
        }
        ans.push_back(v);
    }

    void topological_sort() {
        visited.assign(n, false);
        ans.clear();
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());
    }

    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        this->n = n;
        // Reset all the variables
        visited.assign(n, false);
        adj.assign(n, vector<int>());

        for (auto& e : edges) {
            adj[e[0]-1].push_back(e[1]-1);
        }
        topological_sort();
        return ans;
    }

    bool cycle(int v, vector<int>& color, vector<vector<int>>& adj) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 0) {
                if (cycle(u, color, adj)) {
                    return true;
                }
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }

    bool hasCycle(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]-1].push_back(edge[1]-1);
        }
        vector<int> color(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                if (cycle(i, color, adj)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        // Check for cycles
        if (hasCycle(r, k) || hasCycle(c, k)) {
            return {};
        }

        // Get topological orders
        vector<int> rowOrder = topoSort(r, k);
        vector<int> colOrder = topoSort(c, k);
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; ++i) {
            //cout<<rowOrder[i]<<" "<<colOrder[i]<<endl;
            for(int j=0;j<k;++j){
                if(rowOrder[i]==colOrder[j]){
                    ans[i][j]=rowOrder[i]+1;
                }
            }
        }

        return ans;
    }
};
