class Solution {
public:
    map<int,bool>safe;
    map<int,bool>v;
    set<int>ans;
    map<int,bool>st;
    bool dfs(int x,vector<vector<int>>&g){
        if(st[x]){
            return false;
        }
        if(v[x]){
            return true;
        }
        st[x]=true;
        v[x]=true;
        for(auto y:g[x]){
            if(!dfs(y,g)){
                return false;
            }
        }
        ans.insert(x);
        st[x]=false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        safe.clear();
        ans.clear();
        v.clear();
        for(int i=0;i<n;i++){
            safe[i]=true;
        }
        for(int i=0;i<n;i++){
            if(!v[i]){
                dfs(i,g);
            }
        }
        vector<int>as;
        for(auto x:ans){
            as.push_back(x);
        }
        return as;
    }
};