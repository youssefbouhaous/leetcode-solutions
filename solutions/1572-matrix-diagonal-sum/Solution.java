class Solution {
    public int diagonalSum(int[][] mat) {
        int i =0;
        int n = mat.length;
        int j = 0;
        int ans=0;
        while(i<n&&j<n){
            ans+=mat[i++][j++];
        }
        i=0;j=n-1;
        while(i<n&&j>-1){
            ans+=mat[i++][j--];
        }
        if(n%2==1)ans-=mat[n/2][n/2];
        return ans;
    }
}