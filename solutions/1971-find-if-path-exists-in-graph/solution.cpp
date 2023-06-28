class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>u(n,false);
        queue<int>q;
        q.push(source);
        u[source]=1;
        map<int,vector<int>>g;
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(auto x:g[v]){
                if(u[x]!=1){
                    u[x]=1;
                    q.push(x);
                }
            }
        }
        return u[destination];
    }
};