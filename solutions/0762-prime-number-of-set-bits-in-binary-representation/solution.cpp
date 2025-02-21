class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int n=right;
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i] && (long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        int res=0;
        for(int i=left;i<=right;i++){
            int t=i;
            int ans=0;
            while(t){
                if(t&1)ans++;
                t/=2;
            }
            if(is_prime[ans])res++;
        }
        return res;
    }
};