class Solution {
    public int search(int[] a, int t) {
        int l=0;
        int n=a.length;
        int r=n-1;
        int p=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m!=n-1 && a[m]>a[m+1]){
                p=m;break;
            }
            if(a[m]>=a[0]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        //System.out.println(p);
        if(p!=-1){
            l=p+1;
            r=n-1;
            while(l<=r){
                int m=(l+r)/2;
                if(a[m]==t){
                    return m;
                }
                if(t>a[m]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        l=0;
        r=p;
        if(p==-1){
            r=n-1;
        }
        //System.out.println(r);
        while(l<=r){
            int m=(l+r)/2;
            //System.out.println(m);
            if(a[m]==t){
                return m;
            }
            if(t>a[m]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return -1;
    }
}