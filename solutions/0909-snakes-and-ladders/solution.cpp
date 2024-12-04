class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>dist(n*n+1,-1);
        vector<int>cells(n*n+1);
        vector<int>cols(n);
        int c=1;
        iota(cols.begin(),cols.end(),0);
        for(int row=n-1;row>-1;row--){
            for(int col:cols){
                cells[c++]=board[row][col];
            }
            reverse(cols.begin(),cols.end());
        }
        queue<int>q;
        q.push(1);
        dist[1]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=x+1;i<=min(x+6,n*n);i++){
                int next= (cells[i]==-1)? i:cells[i];
                if(dist[next]==-1){
                    dist[next]=dist[x]+1;
                    q.push(next);
                }
            }
        }
        return dist[n*n];
    }
};