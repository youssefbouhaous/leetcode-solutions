class Solution {
    vector<vector<int>>ans;
    vector<int>path;
    int n;
    void dfs(int x,vector<vector<int>>& g){
        if(x==n-1){
            ans.push_back(path);
            return;
        }
        for(auto y:g[x]){
            path.push_back(y);
            dfs(y,g);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n=g.size();
        path.push_back(0);
        dfs(0,g);
        return ans;
    }
};