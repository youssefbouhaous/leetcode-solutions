class Solution {
    public int maxProduct(int n) {
        int a=0;
        int b=0;
        while(n>0){
            if(n%10>=a){
                b=a;
                a=n%10;
            }else if(n%10>b)b=n%10;
            n/=10;
        }
        return a*b;
    }
}