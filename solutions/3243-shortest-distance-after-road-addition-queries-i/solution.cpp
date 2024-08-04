class Solution {
    map<int,vector<pair<int,int>>>g;
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int>dis(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            dis[i]=n-i-1;
            g[i+1].push_back({i,dis[i]});
        }
        for(auto x:q){
            int u=x[0];
            int v=x[1];
            g[v].push_back({u,dis[v]+1});
            queue<pair<int,int>>qq;
            qq.push({v,dis[v]});
            while(!qq.empty()){
                auto [nxt,d]=qq.front();
                qq.pop();
                for(auto y:g[nxt]){
                    if(dis[y.first]>d+1){
                        dis[y.first]=d+1;
                        qq.push({y.first,dis[y.first]});
                    }
                }
            }
            ans.push_back(dis[0]);
        }
        return ans;
    }
};