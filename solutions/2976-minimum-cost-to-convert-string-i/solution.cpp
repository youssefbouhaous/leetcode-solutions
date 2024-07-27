class Solution {
public:
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;

    void dijkstra(int s, vector<int> & d, vector<int> & p) {
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
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        adj.resize(26);
        map<pair<int,int>,int>ncost;
        int n=cost.size();
        for(int i=0;i<n;i++){
            if(ncost[{original[i],changed[i]}]==0)
            ncost[{original[i],changed[i]}]=cost[i];
            else
            ncost[{original[i],changed[i]}]=min(ncost[{original[i],changed[i]}],cost[i]);
        }
        for(auto x:ncost){
            adj[x.first.first-'a'].push_back({x.first.second-'a',x.second});
        }
        vector<vector<int>>alld(26,vector<int>(26,INF));
        for(auto a='a';a<='z';a++){
            for(auto b='a';b<='z';b++){
                int mx=INF;
                vector<int>d(26);
                vector<int>p(26);
                for(int i=0;i<26;i++){
                    d[i]=INF;
                }
                dijkstra(a-'a',d,p);
                alld[a-'a'][b-'a']=d[b-'a'];
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(alld[source[i]-'a'][target[i]-'a']==INF){
                    return -1;
                }
                ans+=alld[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};