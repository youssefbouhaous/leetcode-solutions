class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
     vector<int>ansb(n,INT_MAX);
    vector<int>ansr(n,INT_MAX);
     ansb[0]=0;
     ansr[0]=0;
        map<pair<int,int>,bool>vis;
        vis[{0,0}]=true;
        vis[{0,1}]=true;
        map<pair<int,int>,int>d;
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            vector<vector<int>>* v=nullptr;
            if(x.second)v=&r;
            else v=&b;
            for(auto y:(*v)){
                if(y[0]==x.first && vis.find({y[1],1-x.second})==vis.end()){
                    vis[{y[1],1-x.second}]=true;
                    q.push({y[1],1-x.second});
                    if(x.second==1 && ansb[y[1]]>ansr[x.first]+1){
                        ansb[y[1]]=ansr[x.first]+1;
                    }
                    if(x.second==0 && ansr[y[1]]>ansb[x.first]+1){
                        ansr[y[1]]=ansb[x.first]+1;
                    }
                }
            }
        }
     
     vector<int>ans(n,INT_MAX);
     for(int i=0;i<n;i++){
        ans[i]=min(ansr[i],ansb[i]);
        if(ans[i]==INT_MAX)ans[i]=-1;
     }
     return ans;
    }
};