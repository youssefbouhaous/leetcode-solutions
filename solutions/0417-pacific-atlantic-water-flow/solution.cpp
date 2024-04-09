class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        map<pair<int,int>,bool>isA;
        map<pair<int,int>,bool>isP;
        queue<pair<int,int>>q;
        int n=h.size();
        int m=h[0].size();
        for(int i=0;i<n;i++){
            isP[{i,0}]=true;
            isA[{i,m-1}]=true;
            q.push({i,0});
            q.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            isP[{0,i}]=true;
            isA[{n-1,i}]=true;
            q.push({0,i});
            q.push({n-1,i});
        }
        while(!q.empty()){
            auto nxt=q.front();
            q.pop();
            int i=nxt.first;int j=nxt.second;
            vector<pair<int,int>>xy={{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
            if(isA[nxt]){
                for(auto r:xy){
                    if(r.first>=0 && r.first<n && r.second>=0 && r.second<m){
                        if(!isA[r]){
                            if(h[r.first][r.second]>=h[i][j]){
                                isA[r]=true;
                                q.push(r);
                            }
                        }
                    }
                }
            }
            if(isP[nxt]){
                for(auto r:xy){
                    if(r.first>=0 && r.first<n && r.second>=0 && r.second<m){
                        if(!isP[r]){
                            if(h[r.first][r.second]>=h[i][j]){
                                isP[r]=true;
                                q.push(r);
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isA[{i,j}] && isP[{i,j}]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};