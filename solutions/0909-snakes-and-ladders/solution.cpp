class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>dist(n*n+1,-1);
        vector<int>cells(n*n+1);
        vector<int>columns(n);
        iota(columns.begin(),columns.end(),0);
        int c=1;
        for(int row=n-1;row>-1;row--){
            for(int col:columns){
                cells[c++]=board[row][col];
            }
            reverse(columns.begin(),columns.end());
        }
        queue<pair<int,bool>>q;
        q.push({1,false});
        dist[1]=0;
        map<int,bool>vis;
        while(!q.empty()){
            auto [x,is]=q.front();
            q.pop();
            for(int i=x+1;i<=min(x+6,n*n);i++){
                int destination=(cells[i]==-1)?i:cells[i];
                if(dist[destination]==-1){
                    dist[destination]=dist[x]+1;
                    q.push({destination,false});
                }
            }
        }
        cout<<dist[n*n-1];
        return dist[n*n];
    }
};