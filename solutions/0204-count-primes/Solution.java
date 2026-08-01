class Solution {
    public int countPrimes(int n) {
        if(n<2)return 0;
        int[] primes = new int[n+1];
        primes[0]=1;
        primes[1]=1;
        for(int i=2;i<=n;i++){
            if(primes[i]==0){
                for(long j=(long)i*i;j<n;j+=i){
                    primes[(int)j]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(primes[i]==0)ans++;
        }
        return ans;
    }
}