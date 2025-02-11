class Solution {
    bool vis[1001]={};
    int n;
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=rooms.size();
        for(int i=0;i<n;i++){
            g[i]=rooms[i];
        }
        dfs(0);
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};