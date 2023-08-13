class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        map<int,vector<int>>g;
        set<pair<int,int>>cc;
        for(int i=0;i<con.size();i++){
            g[con[i][0]].push_back(con[i][1]);
            g[con[i][1]].push_back(con[i][0]);
            cc.insert({con[i][0],con[i][1]});
        }
        int c=0;
        queue<int>q;
        q.push(0);
        vector<bool>v(n,false);
        while(!q.empty()){
            int next=q.front();
            q.pop();
            v[next]=true;
            for(auto x:g[next]){
                if(v[x]==false){
                    bool f=0;
                    q.push(x);
                    v[x]=true;
                    if(cc.find({x,next}) == cc.end()){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};