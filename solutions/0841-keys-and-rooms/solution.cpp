class Solution {
public:
    map<int,set<int>>g;
    map<int,bool>v;
    void dfs(int x){
        for(auto y : g[x]){
            if(v[y]!=true){
                v[y]=true;
                dfs(y);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                g[i].insert(rooms[i][j]);
            }
        }
        v[0]=true;
        dfs(0);
        for(int i=0;i<n;i++){
            if(!v[i]){
                return false;
            }
        }
        return true;
    }
};