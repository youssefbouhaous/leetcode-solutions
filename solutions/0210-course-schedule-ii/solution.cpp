class Solution {
public:
map<int,vector<int>>adj;
    map<int,int>v;
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
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(dfs(i)){
                return sol;
            }
        }
        v.clear();
        map<int,bool>aa;
        for(int i=0;i<n;i++){
            if(v[i]==0){
            stack<int>s;
            s.push(i);
            while(!s.empty()){
                int nxt=s.top();
                if(aa[nxt]){
                    s.pop();
                    continue;
                }
                v[nxt]++;
                bool f=true;
                if(adj[nxt].empty()){
                    sol.push_back(nxt);
                    aa[nxt]=true;
                    s.pop();
                    continue;
                }
                for(int j:adj[nxt]){
                    if(!aa[j]){
                        f=false;
                        v[j]++;
                        s.push(j);
                    }
                }
                if(f && !aa[nxt]){
                    sol.push_back(nxt);
                    s.pop();
                    aa[nxt]=true;
                }
            }
            }
        }
        return sol;
    }
};