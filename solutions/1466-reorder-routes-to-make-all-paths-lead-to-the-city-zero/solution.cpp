class Solution {
public:
    int c=0;
    map<int,vector<int>>g;
    map<int,vector<int>>gto;
    map<int,bool>vv;
    void dfs(int v,vector<vector<int>>& con){
        vv[v]=true;
        for(auto x:g[v]){
            if(vv[x]==true) continue;
            if(gto[x].empty()){
                c++;
            }
            else{
                bool f=0;
                for(auto y:gto[x]){
                    if(y==v){
                        f=1;
                    }
                }
                if(f==0){
                    c++;
                }
            }
            dfs(x,con);
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        c=0;
        for(auto x:con){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            gto[x[0]].push_back(x[1]);
        }
        dfs(0,con);
        return c;
    }
};