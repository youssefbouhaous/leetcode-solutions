


class Solution {
    const int INF = 1000000000;
    

    void dijkstra(int s, vector<int> & d, vector<int> & p, vector<int>& disappear,vector<vector<pair<int, int>>>& adj) {
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

                if (d[v] + len < d[to] && d[v]+len<disappear[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        map<pair<int,int>,int>dis;
        vector<vector<pair<int, int>>> adj(n);
        vector<int>d;
        vector<int>p;
        for(auto x:edges){
            dis[{x[0],x[1]}]= (dis[{x[0],x[1]}]==0) ? x[2] : min(dis[{x[0],x[1]}],x[2]);
        }
        for(auto x:dis){
            adj[x.first.first].push_back({x.first.second, x.second});
            adj[x.first.second].push_back({x.first.first,x.second});
        }
        dijkstra(0,d,p,disappear,adj);
        for(int i=0;i<n;i++){
            if(d[i]==INF){
                d[i]=-1;
            }
        }
        return d;
    }
};