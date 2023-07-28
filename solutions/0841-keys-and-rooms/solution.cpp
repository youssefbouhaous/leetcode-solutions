class Solution {
public:
    map<int,vector<int>>g;
    map<int,bool>v;
    void dfs(int s){
        v[s]=true;
        for(auto y:g[s]){
            if(v[y]!=true){
                dfs(y);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        for(int i=0;i<rooms.size();i++){
            for(auto x:rooms[i]){
                if(x!=i){
                    g[i].push_back(x);
                }
            }
        }
        dfs(0);
        for(int i=0;i<rooms.size();i++){
            if(v[i]!=true){
                return false;
            }
        }
        return true;
    }
};