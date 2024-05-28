class Solution {
public:
    int countGoodNumbers(long long n) {
        long long a=(n+1)/2;
        long long b=(n)/2;
        long long res=1;
        long long o=5;
        const int mod=1e9+7;
        while(a){
            if(a&1){
                res=res*o%mod;
            }
            a>>=1;
            o=o*o%mod;
        }
        o=4;
        while(b){
            if(b&1){
                res=res*o%mod;
            }
            b>>=1;
            o=o*o%mod;
        }
        return res;
    }
};