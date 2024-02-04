class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int x,vector<int>&path,vector<vector<int>>& g){
        if(x==g.size()-1){
            ans.push_back(path);
            return;
        }
        for(auto y:g[x]){
            path.push_back(y);
            dfs(y,path,g);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<int>path;
        path.push_back(0);
        dfs(0,path,g);
        return ans;
        
    }
};