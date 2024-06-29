class TreeAncestor {
public:
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int>& parent) {
        up.assign(n,vector<int>(20,-1));
        for(int v=0;v<n;v++){
            up[v][0] = parent[v];
        }
        for(int j = 1; j < 20; j++){
            for(int v = 0; v <n; v++){
                if (up[v][j - 1] != -1)
                    up[v][j] = up[up[v][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int j = 0; j < 20; j++){
            if(k & (1 << j)){
                node = up[node][j];
                if (node == -1) break; 
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */