class Solution {
    public boolean canJump(int[] n) {
        boolean[] p= new boolean[n.length];
        p[0]=true;
        for(int i=0;i<n.length;i++){
            if(p[i]){
            for(int j=i+1;j<=Math.min(n[i]+i,n.length-1);j++){
                p[j]=true;
            }
            }
        }
        return p[n.length-1];
    }
}