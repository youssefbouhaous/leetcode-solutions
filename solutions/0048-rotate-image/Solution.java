class Solution {
    public void rotate(int[][] mat) {
        int n = mat.length;
        int l = 0;
        int r = n-1;
        while(l<r){
            for(int i=0;i<r-l;i++){
                int tmp = mat[l][l+i];
                mat[l][l+i] = mat[r-i][l];

                mat[r-i][l] = mat[r][r-i];

                mat[r][r-i] = mat[l+i][r];

                mat[l+i][r] = tmp;
            }
            l++;r--;
        }
    }
}