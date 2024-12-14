class Solution {
    public int trailingZeroes(int n) {
        if(n==0) return 0;
        int c5=0;
        while(n!=0){
            c5+=n/5;
            n/=5;
        }
        return c5;
    }
}