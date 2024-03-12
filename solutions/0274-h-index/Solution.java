class Solution {
    public int hIndex(int[] c) {
        Arrays.sort(c);
        int l=0;
        int r=c.length;
        int n=c.length;
        int ans=0;
        while(l<r){
            int m=(l+r+1)/2;
            int ccc=0;
            for(int i=0;i<n;i++){
                if(c[i]>=m){
                    ccc++;
                }
            }
            if(ccc>=m){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }
}