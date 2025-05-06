class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int,bool>vis;
        queue<int>q;
        int n=rooms.size();
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto to:rooms[x]){
                if(!vis[to]){
                    vis[to]=true;
                    q.push(to);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false)return false;
        }
        return true;
    }
};