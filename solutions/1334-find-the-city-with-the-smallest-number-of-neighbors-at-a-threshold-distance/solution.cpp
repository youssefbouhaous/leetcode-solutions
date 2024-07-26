class Solution {
public:
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;
    int t;
    int cnt=0;
    void dijkstra(int s) {
        vector<int> d; vector<int> p;
        int n = adj.size();
        d.assign(n, INF);
        p.assign(n, -1);
        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
        for(auto x:d){
            if(x<=t){
                cnt++;
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        t=dt;
        adj.resize(n,vector<pair<int,int>>());
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }   
        int mx=INF;
        int ans=0;
        for(int i=0;i<n;i++){
            cnt=0;
            dijkstra(i);
            if(cnt<=mx){
                ans=i;
                mx=cnt;
            }
        }
        return ans;
    }
};