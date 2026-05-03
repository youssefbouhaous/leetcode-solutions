class NumMatrix {
    private int[][] pre;
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        pre = new int[n+1][m+1];
        for(int i=0;i<n;i++){
            pre[i+1][1] = matrix[i][0] + pre[i][1];
        }
        for(int i=0;i<m;i++){
            pre[1][i+1] = matrix[0][i] + pre[1][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                pre[i+1][j+1] = matrix[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j]; 
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1]-pre[row1][col2+1]-pre[row2+1][col1]+pre[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */