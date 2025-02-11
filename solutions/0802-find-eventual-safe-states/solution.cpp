class Solution {
    int n;
    unordered_map<int,vector<int>>g;
    bool vis[10001]={};
    bool safe[10001]={};
    vector<int>v;
    void dfs(int x){
        vis[x]=true;
        bool ans=true;
        for(auto y:g[x]){
            if(!vis[y]){
                vis[y]=true;
                dfs(y);
            }
            ans&=safe[y];
        }
        safe[x]=ans;
        if(safe[x]){
            v.push_back(x);
        }
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n=graph.size();
        for(int i=0;i<n;i++){
            for(auto y:graph[i]){
                g[i].push_back(y);
            }
        }
        for(int i=0;i<n;i++){
            dfs(i);
        }
        set<int>st;
        for(auto x:v){
            st.insert(x);
        }
        return vector<int>(st.begin(),st.end());
    }
};