vector<long long> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<long long> primes;
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}
vector<long long> primes=sieve(1000000);
class Solution {
public:
    
    int nonSpecialCount(int l, int r) {
        int ans=r-l+1;
        long long ll=l;
        long long rr=r;
        for(auto x:primes){
            if(x*x>rr){
                break;
            }
            if(x*x>=ll && x*x<=rr){
                ans--;
            }
        }
        return ans;
    }
};