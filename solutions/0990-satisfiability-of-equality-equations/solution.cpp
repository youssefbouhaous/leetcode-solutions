class Solution {
public:
    map<int,int>v;
    int find(int x){
        if(v[x]==x){
            return x;
        }
        return v[x]=find(v[x]);
    }
    void funion(int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            v[y]=x;
        }
    }
    map<int,vector<int>>g;
    map<int,vector<int>>gg;
    bool f=false;
    void dfs(int r,int y,map<int,bool>&vv){
        vv[r]=true;
        for(auto yy:g[r]){
            if(yy!=r && !vv[yy]){
                vv[yy]=true;
                if(yy==y || find(yy)==find(y)){
                    f=true;
                    return;
                }
                dfs(yy,y,vv);
            }
        }
    }
    bool equationsPossible(vector<string>& e) {
        for(int i='a';i<='z';i++){
            v[i]=i;
        }
        vector<pair<int,int>>ff;
        vector<pair<int,int>>vvv;
        for(auto rr:e){
            int a=rr[0];
            int r=rr[1];
            int b=rr[3];
            if(r=='!'){
                if(find(a)==find(b)){
                    return false;
                }
                gg[a].push_back(b);
                gg[b].push_back(a);
            }
            else{
                funion(a,b);
            }
        }
        for(auto x:e){
            if(x[1]=='!' && find(x[0])==find(x[3])){
                return false;
            }
        }
        return true;
    }
};