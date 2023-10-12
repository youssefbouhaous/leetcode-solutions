class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return 0<=i && i<n && 0<=j && j<m;
    }
    bool border(int i,int j){
        return i==0 || i==n-1 || j==0 || j==m-1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       n=maze.size();
       m=maze[0].size();
       queue<pair<int,int>>q;
       map<pair<int,int>,int>d;
       map<pair<int,int>,bool>v;
       q.push({entrance[0],entrance[1]});
       v[q.front()]=1;
       while(!q.empty()){
           pair<int,int> x = q.front();
           q.pop();
           int i=x.first,j=x.second;
           if(border(i,j) && (i!=entrance[0] || j!=entrance[1])){
               return d[{i,j}];
           }
           if(valid(i-1,j) && maze[i-1][j]=='.' && v[{i-1,j}]==0){
               d[{i-1,j}]=d[{i,j}]+1;
               v[{i-1,j}]=1;
               q.push({i-1,j});
           }
           if(valid(i+1,j) && maze[i+1][j]=='.' && v[{i+1,j}]==0){
               d[{i+1,j}]=d[{i,j}]+1;
               v[{i+1,j}]=1;
               q.push({i+1,j});
           }
           if(valid(i,j-1) && maze[i][j-1]=='.' && v[{i,j-1}]==0){
               d[{i,j-1}]=d[{i,j}]+1;
               v[{i,j-1}]=1;
               q.push({i,j-1});
           }
           if(valid(i,j+1) && maze[i][j+1]=='.' && v[{i,j+1}]==0){
               d[{i,j+1}]=d[{i,j}]+1;
               v[{i,j+1}]=1;
               q.push({i,j+1});
           }
           
       }
       return -1;
    }
};