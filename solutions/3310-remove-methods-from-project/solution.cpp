class Solution {
    int parent[100005];
    int rank[100005];
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int find_set(int v) {
    if (v == parent[v])
        return v;
        return parent[v] = find_set(parent[v]);
    }
   bool vis[100005]={false};
   vector<vector<int>>g;
    void dfs(int v){
        vis[v]=true;
        for(auto x:g[v]){
            if(!vis[x]){
                vis[x]=true;
                dfs(x);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>no;
        g.resize(n+1);
        for(int i=1;i<=n;i++){
            make_set(i);
            no.push_back(i-1);
        }
        for(auto x:invocations){
            int a=x[0];
            int b=x[1];
            a++;b++;
            g[a].push_back(b);
            union_sets(a,b);
        }
        dfs(k+1);
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(find_set(k+1)==find_set(i) && !vis[i]){
                return no;
            }
            else if(find_set(k+1)!=find_set(i)){
                ans.push_back(i-1);
            }
        }
        return ans;
    }
};