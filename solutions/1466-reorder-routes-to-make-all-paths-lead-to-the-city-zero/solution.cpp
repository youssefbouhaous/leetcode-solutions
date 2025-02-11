class Solution {
    bool vis[50005]={};
    unordered_map<int,vector<int>>g;
    unordered_map<int,vector<int>>gr;
    int ans=0;
    void dfs(int x){
        vis[x]=true;
        for(auto y:g[x]){
            if(!vis[y]){
                vis[y]=true;
                dfs(y);
            }
        }
        for(auto y:gr[x]){
            if(!vis[y]){
                vis[y]=true;
                ans++;
                dfs(y);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& c) {
        for(auto x:c){
            g[x[1]].push_back(x[0]);
            gr[x[0]].push_back(x[1]);
        }
        dfs(0);
        return ans;
    }
};