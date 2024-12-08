class Solution {
    int n;
    unordered_map<int,vector<int>> adj;
    vector<char> color;
    vector<int> parent;

    bool dfs(int v) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        n=numCourses;
        color.assign(n, 0);
        parent.assign(n, -1);
        unordered_map<int,vector<int>>radj;
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
            radj[x[1]].push_back(x[0]);
        }
        vector<int>ans;
        queue<int>q;
        unordered_map<int,bool>vis;
        for(auto x:p){
            if(dfs(x[0])){
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]&& adj[i].size()==0){
                //vis[i]=true;
                q.push(i);
            }
        }
        //cout<<q.size();
        while(!q.empty()){
            int nxt=q.front();
            q.pop();
            if(!vis[nxt])
            ans.push_back(nxt);
            vis[nxt]=true;
            //cout<<"ok";
            for(auto x:radj[nxt]){
                bool f=true;
                for(auto y:adj[x]){
                    if(!vis[y]){
                        f=false;
                        break;
                    }
                }
                if(f){
                    q.push(x);
                }
            }
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};