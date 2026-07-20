class Solution {
    public long gcd(long a,long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    public long interchangeableRectangles(int[][] r) {
        Map<String,Long> mp = new HashMap<>();
        int n = r.length;
        for(int i=0;i<n;i++){
            int a = r[i][0];int b=r[i][1];
            long g = gcd(a,b);
            a/=g;b/=g;
            String u=a+"-"+b;
            mp.put(u,mp.getOrDefault(u,0L)+1L);
            // System.out.println(u);
        }
        long ans=0;
        for(String x:mp.keySet()){
            long nn = mp.get(x);
            // System.out.print(nn);
            ans+=nn*(nn-1)/2;
        }
        return ans;
    }
}