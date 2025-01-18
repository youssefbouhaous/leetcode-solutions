class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>,bool>vis;
        queue<pair<vector<vector<int>>,int>>q;
        q.push({board,0});
        vector<vector<int>>ans={{1,2,3},{4,5,0}};
        while(!q.empty()){
            auto nxt=q.front();
            auto e=nxt.first;
            auto d=nxt.second;
            vis[e]=true;
            q.pop();
            if(e==ans){return d;}
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    if(e[i][j]==0){
                        if(i+1<2){
                            vector<vector<int>>nw(e.begin(),e.end());
                            swap(nw[i+1][j],nw[i][j]);
                            if(!vis[nw]){
                            vis[nw]=true;
                            q.push({nw,d+1});
                            }
                        }
                        if(i-1>=0){
                            vector<vector<int>>nw(e.begin(),e.end());
                            swap(nw[i-1][j],nw[i][j]);
                            if(!vis[nw]){
                            vis[nw]=true;
                            q.push({nw,d+1});
                            }
                        }
                        if(j+1<3){
                            
                            vector<vector<int>>nw(e.begin(),e.end());
                            swap(nw[i][j+1],nw[i][j]);
                            if(!vis[nw]){
                            vis[nw]=true;
                            q.push({nw,d+1});
                            }
                        }
                        if(j-1>=0){
                            
                            vector<vector<int>>nw(e.begin(),e.end());
                            swap(nw[i][j-1],nw[i][j]);
                            if(!vis[nw]){
                            vis[nw]=true;
                            q.push({nw,d+1});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};