class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] ans = new int[n][m];
        for(int i=0;i<m;i++){
            int x=0;
            int y=i;
            List<Integer> tmp = new ArrayList<>();
            while(x<n && y<m){
                tmp.add(mat[x++][y++]);
            }
            Collections.sort(tmp);
            x=0;
            y=i;
            int j=0;
            while(x<n && y<m){
                ans[x++][y++]=tmp.get(j++);
            }
        }
        for(int i=0;i<n;i++){
            int x=i;
            int y=0;
            List<Integer> tmp = new ArrayList<>();
            while(x<n && y<m){
                tmp.add(mat[x++][y++]);
            }
            Collections.sort(tmp);
            x=i;
            y=0;
            int j=0;
            while(x<n && y<m){
                ans[x++][y++]=tmp.get(j++);
            }
        }
        return ans;
    }
}