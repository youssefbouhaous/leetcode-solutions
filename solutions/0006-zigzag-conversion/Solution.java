class Solution {
    public String convert(String s, int n) {
        if(n==1)return s;
        char[][] mat = new char[n][1000];
        int x=0;
        int y=0;
        int len = s.length();
        int d=0;
        for(int i=0;i<len;i++){
            mat[x][y]=s.charAt(i);
            if(d==0){
                x++;
                if(x>=n){
                    d=1;x= n>1? n-2:n-1 ;
                    y++;
                }
            }else{
                x--;y++;
                if(x<0){
                    x=1;
                    y--;d=0;
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<n;i++){
            for(int j=0;j<1000;j++){
                if(mat[i][j]!=0)ans.append(mat[i][j]);
            }
        }
        return ans.toString();
    }
}