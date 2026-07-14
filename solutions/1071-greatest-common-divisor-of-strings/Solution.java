class Solution {
    public int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    public String gcdOfStrings(String a, String b) {
        int n = a.length();
        int m = b.length();
        int g = gcd(n,m);
        String d1 = a.substring(0,g);
        String d2 = b.substring(0,g);
        if(!d1.equals(d2))return "";
        int i = 0;
        int j = 0;
        while(i<n){
            i+=g;
            if(!a.substring(i-g,i).equals(d1)) return "";
        }
        while(j<m){
            j+=g;
            if(!b.substring(j-g,j).equals(d1)) return "";
        }
        return d1;
    }
}