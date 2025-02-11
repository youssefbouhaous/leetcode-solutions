class Solution {
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        unordered_map<int,vector<int>>gr;
        unordered_map<int,vector<int>>gb;
        const int INF=INT_MAX;
        vector<int>dr(n,INF);
        vector<int>db(n,INF);
        dr[0]=0;
        db[0]=0;
        for(auto x:r)gr[x[0]].push_back(x[1]);
        for(auto x:b)gb[x[0]].push_back(x[1]);
        queue<pair<int,int>>q;
        q.push({0,1});
        q.push({0,0});
        bool vis[101][2];
        for(int i=0;i<n;i++){
            vis[i][0]=false;vis[i][1]=false;
        }
        while(!q.empty()){
            auto [e,c]=q.front();q.pop();
            vis[e][c]=true;
            if(c==1){
                for(auto x:gr[e]){
                    if(dr[x]==INF)dr[x]=db[e]+1;
                    else dr[x]=min(dr[x],db[e]+1);
                    if(!vis[x][0]){
                        vis[x][0]=true;
                        q.push({x,0});}
                }
            }else{
                for(auto x:gb[e]){
                    if(db[x]==INF)db[x]=dr[e]+1;
                    else db[x]=min(db[x],dr[e]+1);
                    if(!vis[x][1]){
                        vis[x][1]=true;
                        q.push({x,1});}
                }
            }
        }
        vector<int>ans={0};
        for(int i=1;i<n;i++){
            if(min(dr[i],db[i])==INF)ans.push_back(-1);
            else ans.push_back(min(dr[i],db[i]));
        }
        return ans;
    }
};