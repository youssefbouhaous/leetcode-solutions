class Solution {
    bool vis[201]={};
    unordered_map<int,vector<int>>g;
    void dfs(int x){
        vis[x]=true;
        for(auto y:g[x]){
            if(!vis[y]){
                dfs(y);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]==1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;dfs(i);
            }
        }
        return ans;
    }
};