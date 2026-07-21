class Solution {
    int n;
    int[][] g;
    int[][] ans;
    Set<String> vis = new HashSet<>();
    int[][] d = new int[][]{
        {-1,-1},{-1,0},{-1,1},
        {0,-1}        ,{0,1},
        {1,-1},{1,0},{1,1}
    };
    public boolean valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<n;
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        g=grid;
        if(g[0][0]==1)return -1;
        n = g.length;
        ans = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=-1;
            }
        }
        ans[0][0]=1;
        Deque<int[]> q = new ArrayDeque<>();
        q.addLast(new int[]{0,0});
        vis.add("0-0");
        while(!q.isEmpty()){
            int[] cur = q.pollFirst();
            int i = cur[0];int j = cur[1];
            for(var xy:d){
                int x = i+xy[0];int y=j+xy[1];
                String h = x+"-"+y;
                if(valid(x,y) && g[x][y]==0){
                
                    if(ans[x][y]==-1)ans[x][y]=ans[i][j]+1;
                    else ans[x][y] =Math.min(ans[x][y],ans[i][j]+1);
                    if(!vis.contains(h)){
                    vis.add(h);
                    q.addLast(new int[]{x,y});
                    }           
                }
            }
        }
        return ans[n-1][n-1];
    }
}