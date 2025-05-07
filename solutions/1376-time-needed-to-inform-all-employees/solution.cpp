class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& t) {
        vector<vector<int>>adj(n,vector<int>(0));
        for(int i=0;i<n;i++){
            if(i==h)continue;
            adj[m[i]].push_back(i);
        }
        queue<int>q;
        vector<int>d(n,INT_MAX);
        vector<int>vis(n,false);
        vis[h]=true;
        d[h]=0;
        q.push(h);
        int ans=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:adj[x]){
                if(!vis[y]){
                    vis[y]=true;
                    d[y]=d[x]+t[x];
                    ans=max(ans,d[y]);
                    q.push(y);
                }
            }
        }
        return ans;
    }
};