class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int ly=0;
        int ry=matrix.length-1;
        int m=matrix[0].length;
        while(ly<=ry){
            int my=(ly+ry)/2;
            if(matrix[my][0]<=target && matrix[my][m-1]>=target){
                int l=0;
                int r=m-1;
                while(l<=r){
                    int mx=(l+r)/2;
                    if(matrix[my][mx]==target){
                        return true;
                    }
                    if(matrix[my][mx]<target){
                        l=mx+1;
                    }
                    else{
                        r=mx-1;
                    }
                }
            }
            if(matrix[my][0]>=target){
                ry=my-1;
            }
            else{
                ly=my+1;
            }
        }
        return false;
    }
}