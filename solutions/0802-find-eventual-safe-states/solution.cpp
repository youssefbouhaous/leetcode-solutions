class Solution {
public:
    map<int,bool>vis;
    map<int,vector<int>>adj;
    set<int>ans;
    bool dfs(int x){
        bool f=true;
        vis[x]=true;
        if(adj[x].size()==0){
            ans.insert(x);
            return true;
        }
        for(auto y:adj[x]){
            if(vis.find(y)==vis.end()){
                f&=dfs(y);
            }
            else if(ans.count(y)==0){
                return false;
            }
        }
        if(f){
            ans.insert(x);
            return true;
        }
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            adj[i]=graph[i];
        }
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                dfs(i);
            }
        }
        vector<int>ff;
        for(auto x:ans){
            ff.push_back(x);
        }
        return ff;
    }
};