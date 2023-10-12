class Solution {
public:
    vector<vector<int>>ans;
    map<int,bool>visited;
    map<int,vector<int>>g;
    map<int,int>low,id;
    int timer=0;
    void dfs(int v,int p=-1){
        visited[v]=true;
        id[v]=low[v]=timer++;
        for(auto x:g[v]){
            if(x==p) continue;
            if(!visited[x]){
                dfs(x,v);
                low[v]=min(low[v],low[x]);
                if(id[v]<low[x]){
                    ans.push_back({x,v});
                }
            }
            else{
                low[v]=min(low[v],id[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cnx) {
        for(auto x:cnx){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        dfs(0);
        return ans;
    }
};