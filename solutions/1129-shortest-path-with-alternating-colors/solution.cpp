class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        map<int,vector<int>>gr;
        map<int,vector<int>>gb;
        vector<int>dr(n,-1);
        vector<int>db(n,-1);
        dr[0]=0;
        db[0]=0;
        for(auto x:r){
            gr[x[0]].push_back(x[1]);
        }
        for(auto x:b){
            gb[x[0]].push_back(x[1]);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        map<pair<int,int>,bool>v;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            v[p]=true;
            if(p.second==0){
                for(auto x:gb[p.first]){
                    if(db[x]==-1){
                        db[x]=dr[p.first]+1;
                    }
                    else{
                        db[x]=min(db[x],dr[p.first]+1);
                    }
                    if(!v[{x,1}])
                    q.push({x,1});
                }
            }
            else{
                for(auto x:gr[p.first]){
                    if(dr[x]==-1){
                        dr[x]=db[p.first]+1;
                    }
                    else{
                        dr[x]=min(dr[x],db[p.first]+1);
                    }
                    if(!v[{x,0}])
                    q.push({x,0});
                }
            }
        }
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++){
            if(db[i]==-1 || dr[i]==-1){
                ans.push_back(max(db[i],dr[i]));
            }
            else{
                ans.push_back(min(db[i],dr[i]));
            }
        }
        return ans;
    }
};