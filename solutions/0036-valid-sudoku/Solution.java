class Solution {
    public boolean isValidSudoku(char[][] b) {
        for(int i=0;i<9;i++){
            int[] c = new int[9];
            for(int j=0;j<9;j++){
                if(b[i][j]=='.')continue;
                int e = b[i][j]-'1';
                c[e]++;
                if(c[e]>1)return false;
            }
            c = new int[9];
            for(int j=0;j<9;j++){
                if(b[j][i]=='.')continue;
                int e = b[j][i]-'1';
                c[e]++;
                if(c[e]>1)return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int[] c = new int[9];
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(b[k][l]=='.')continue;
                        int e = b[k][l]-'1';
                        c[e]++;
                        if(c[e]>1)return false;
                    }
                }
            }
        }
        return true;
    }
}