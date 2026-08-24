class Solution {
    // StringBuilder tmp=new StringBuilder();
    int n;
    int m;
    boolean valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    boolean[][] vis;
    char[][] board;
    String w;
    boolean f(int i,int j,int cur){
        if(!valid(i,j) || vis[i][j]){
            return false;
        }
        if(board[i][j]!=w.charAt(cur))return false;
        else if(cur==w.length()-1)return true;
        vis[i][j]=true;
        boolean found=f(i+1,j,cur+1)|f(i-1,j,cur+1)|f(i,j+1,cur+1)|f(i,j-1,cur+1);
        vis[i][j]=false;
        return found;
    }
    public boolean exist(char[][] board, String word) {
        n=board.length;
        m=board[0].length;
        this.board=board;
        w=word;
        vis=new boolean[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(i,j,0))
                return true;
            }
        }
        return false;
    }
}