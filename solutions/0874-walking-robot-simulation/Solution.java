class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int x=0;
        int y=0;
        int d=0;
        int ans = 0;
        int cur = 0;
        HashSet<String> st = new HashSet<>();
        for(int[] yo:obstacles){
            st.add(yo[0]+"-"+yo[1]);
        }
        for(int o:commands){
            cur = x*x+y*y;
            ans = Math.max(ans,cur);
            if(o==-2){
                d= (d+90)%360;
            }else if(o==-1){
                d = (d-90+360)%360;
            }else{
                for(int i=0;i<o;i++){
                    int tx=x;int ty=y;
                    if(d==0)y++;
                    if(d==90)x--;
                    if(d==180)y--;
                    if(d==270)x++;
                    String p = x+"-"+y;
                    if(st.contains(p)){
                        x=tx;y=ty;break;
                    }
                }
            }
            // System.out.println(d+"- x:"+x+"-y:"+y);
            cur = x*x+y*y;
            ans = Math.max(ans,cur);
        }
        return ans;
    }
}