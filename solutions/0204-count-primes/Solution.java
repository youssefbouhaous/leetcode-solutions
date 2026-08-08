class Solution {
    public int countPrimes(int n) {
        if(n<3)return 0;
        boolean[] primes = new boolean[n];
        primes[0]=true;
        primes[1]=true;
        int cnt = 0;
        for(long i=2;i<n;i++){
            if(!primes[(int)i]){
                cnt++;
                for(long j=i*i;j<n;j+=i){
                    primes[(int)j]=true;
                }
            }
        }
        return cnt;
    }
}