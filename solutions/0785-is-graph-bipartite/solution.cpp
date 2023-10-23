class Solution {
public:
    map<int,vector<int>>g;
    map<int,int>vi;
    bool f=true;
    void dfs(int v,int c){
        vi[v]=c;
        for(auto x:g[v]){
            if(vi[x]==0){
                if(c==1){
                    vi[x]=2;
                    dfs(x,2);
                }
                else{
                    vi[x]=1;
                    dfs(x,1);
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++){
            vi[i]=0;
            for(auto x:graph[i]){
                g[i].push_back(x);
                g[x].push_back(i);
            }
        }
        int n=graph.size();
        for(int i=0;i<n;i++){
            if(vi[i]==0){
                dfs(i,1);
            }
        }
       
        for(int i=0;i<n;i++){
            for(auto x:g[i]){
                if(vi[x]==vi[i]){
                    return false;
                }
            }
        }
        return true;
    }
};