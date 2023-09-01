class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return 0<=i && 0<=j && i<m && j<n; 
    }
    bool border(int i,int j){
        return i==0 || j==0 || i==m-1 || j==n-1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       m=maze.size();
       n=maze[0].size();
       queue<pair<pair<int,int>,int>>q;
       q.push({{entrance[0],entrance[1]},0});
       map<pair<int,int>,bool>v;
       v[q.front().first]=true;
       while(!q.empty()){
           pair<int,int>next=q.front().first;
           int d=q.front().second;
           v[next]=true;
           q.pop();
           int i=next.first;
           int j=next.second;
           if(v[{i+1,j}]!=true && valid(i+1,j ) && maze[i+1][j]=='.'){
               if(border(i+1,j)) return d+1;
               v[{i+1,j}]=true;
               q.push({{i+1,j},d+1}); 
           }
           if(v[{i,j+1}]!=true && valid(i,j+1) && maze[i][j+1]=='.'){
               if(border(i,j+1)) return d+1;
               q.push({{i,j+1},d+1});
               v[{i,j+1}]=true; 
           }
           if(v[{i-1,j}]!=true && valid(i-1,j) && maze[i-1][j]=='.'){
               if(border(i-1,j)) return d+1;
               q.push({{i-1,j},d+1});
               v[{i-1,j}]=true; 
           }
           if(v[{i,j-1}]!=true && valid(i,j-1) && maze[i][j-1]=='.'){
               if(border(i,j-1)) return d+1;
               q.push({{i,j-1},d+1});
               v[{i,j-1}]=true; 
           }
       }
       return -1;
    }
};