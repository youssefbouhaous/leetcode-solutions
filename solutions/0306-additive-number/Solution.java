class Solution {
    public boolean isAdditiveNumber(String s) {
        int n = s.length();
        boolean laz = false;
        if(s.charAt(0)=='0')laz=true;
        long a = 0;
        for(int i=0;i<n/2;i++){
            a= a*10+(s.charAt(i)-'0');
            long ta=a;
            long b=0;
            boolean lbz=false;
            if(s.charAt(i+1)=='0')lbz=true;
            for(int j=i+1;j<n-1;j++){
                b=b*10+(s.charAt(j)-'0');
                long tb=b;
                long c=0;
                boolean lcz = false;
                if(s.charAt(j+1)=='0')lcz=true;
                int k=j+1;
                while(k<n){
                    c=c*10+(s.charAt(k)-'0');
                    if(a+b==c){
                        if(k==n-1)return true;
                        a=b;
                        b=c;
                        c=0;
                        if(k<n &&s.charAt(k+1)=='0'){
                            lcz=true;
                            k++;continue;
                        }
                        else lcz=false;
                    }else if(a+b<c)break;
                    k++;
                    if(lcz)break;
                }
                b=tb;
                a=ta;
                if(lbz)break;
            }
            if(laz)break;
        }
        return false;
    }
}