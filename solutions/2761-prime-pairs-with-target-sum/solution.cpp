class Solution {
public:
    vector<int> g(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<int> pr = g(n); 
        unordered_set<int> prSet(pr.begin(), pr.end()); 
        set<vector<int>> ans;
        for (int i = 0; i < pr.size(); i++) {
            int complement = n - pr[i];
            if (prSet.count(complement)) { 
                ans.insert({min(pr[i], complement),max(pr[i], complement)});
            }
        }
        vector<vector<int>>mans;
        for(auto x:ans){
            vector<int>a={x[0],x[1]};
            mans.push_back(a);
        }
        return mans;
    }
};
