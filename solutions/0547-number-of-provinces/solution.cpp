class Solution {
public:
    map<int,bool>vis;
    map<int,vector<int>>adj;
    void dfs(int x){
        vis[x]=true;
        for(auto y:adj[x]){
            if(vis.find(y)==vis.end()){
                dfs(y);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};