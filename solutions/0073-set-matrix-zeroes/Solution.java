class Solution {
    public void setZeroes(int[][] mat) {
        List<int[]> l = new ArrayList<>();
        int n = mat.length;
        int m = mat[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    l.add(new int[]{i,j});
                }
            }
        }
        for(var x:l){
            int i = x[0];
            int j = x[1];
            mat[i] = new int[m];
            for(int ll=0;ll<n;ll++){
                mat[ll][j]=0;
            }
        }

    }
}