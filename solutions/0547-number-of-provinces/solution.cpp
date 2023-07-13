class Solution {
public:
    map<int,set<int>>g;
    map<int,bool>v;
    void dfs(int s){
        v[s]=1;
        for(auto x:g[s]){
            if(v[x]!=1)
            dfs(x);
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        g.clear();
        v.clear();
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==1){
                    g[i].insert(j);
                    g[j].insert(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(v[i]!=1){
            ans++;
            dfs(i);}
        }
        return ans;
    }
};