class Solution {
    public boolean canPlaceFlowers(int[] f, int n) {
        int s = f.length;
        int l = 0;
        int r = 0;
        int c = 0;
        if(s>1 && f[0]==0 && f[1]==0){
            n--;
            f[0]=1;
        }
        else if(s>1 && f[s-1]==0 && f[s-2]==0){
            n--;
            f[s-1]=1;
        }
        if(s>2 && f[s-1]==0 && f[s-2]==0){
            n--;
            f[s-1]=1;
        }
        if(s==1 && f[0]==0)return true;
        if(n<=0)return true;
        while(r<s){
            if(l==r){
                r++;
            }
            else if(f[r]==0){
                c++;
                r++;
                if(r==s-1){
                    //System.out.println(c+" "+n);
                    n-=(c-1)/2;
                    break;
                }
            }
            else{
                l=r;
                r++;
                //System.out.println(c+" "+n);
                n -= (c-1)/2;
                //System.out.println(n);
                c=0;
            }
        }
        return n<=0;
    }
}