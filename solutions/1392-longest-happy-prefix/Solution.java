class Solution {
    record Hash(long h1,long h2){}
    public String longestPrefix(String s) {
        int n = s.length();
        if(n==1)return "";
        long m = 1000_000_009;
        long m2= 1000_000_007;
        long p =31;
        long p2 = 37;
        long[] suf = new long[n+1];
        long pow=1L;
        long h = 0;
        long h2 =0;
        Set<Hash> st = new HashSet<>();
        for(int i=n-1;i>-1;i--){
            int o = s.charAt(i)-'a'+1;
            h=(o+h*p)%m;
            h2=(o+h2*p2)%m2;
            suf[i]=h;
            st.add(new Hash(h,h2));
            // System.out.println(s.substring(i)+"-"+h);
        }
        h=0;
        h2=0;
        pow=1L;
        long pow2=1L;
        int mx=0;
        boolean f=false;
        for(int i=0;i<n-1;i++){
            int o = s.charAt(i)-'a'+1;
            h=(h+o*pow)%m;
            h2=(h2+o*pow2)%m2;
            pow=(pow*p)%m;
            pow2=(pow2*p2)%m2;
            // System.out.println(s.substring(0,i+1)+"-"+h);
            if(st.contains(new Hash(h,h2))){
                f=true;
                mx=i;
            }
        }
        if(!f)return "";
        return s.substring(0,mx+1);
    }
}