class Solution {
    public boolean judgeCircle(String moves) {
        int x=0;
        int y=0;
        int n= moves.length();
        for(int i=0;i<n;i++){
            char m = moves.charAt(i);
            switch(m){
                case 'U':
                    x++;break;
                case 'D':
                    x--;break;
                case 'R':
                    y++;break;
                case 'L':
                    y--;
            }
        }
        
        return x==0 && y==0;
    }
}