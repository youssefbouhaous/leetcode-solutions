class Solution {
    int n;
    int m;
    public boolean valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    public int[] findDiagonalOrder(int[][] mat) {
        n = mat.length;
        m = mat[0].length;
        int i=0;
        int j=0;
        int cnt = 0;
        List<Integer> ans = new ArrayList<>();
        int d =0;
        while(cnt<n*m){
            // System.out.println("i "+i+" j "+j);
            if(valid(i,j)){
                cnt++;
                ans.add(mat[i][j]);
                if(d==0){
                    i--;j++;
                }else{
                    i++;j--;
                }
            }else{
                d = 1-d;
                if(i<0 && j<m){
                    i=0;
                }
                else if(i<0 && j>=m){
                    i=1;j=m-1;
                }
                else if(j<0 && i<n){
                    j=0;
                }
                else if(j<0 && i>=n){
                    j=1;i=n-1;
                }
                else if(i>=n){
                    i=n-1;j+=2;
                }
                else if(j>=m){
                    j=m-1;i+=2;
                }
            }
        }
        int[] t = new int[n*m];
        int ii = 0;
        for(Integer x:ans)t[ii]=ans.get(ii++);
        return t;
    }
}