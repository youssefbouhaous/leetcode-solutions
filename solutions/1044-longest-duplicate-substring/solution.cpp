class Solution {
    struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        const int p1 = 31, p2 = 37;
        const long long m1 = 1e9 + 9, m2 = 1e9 + 7;
        string ans = "";
        
        vector<long long> p_pow1(n), p_pow2(n);
        p_pow1[0] = 1;
        p_pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            p_pow1[i] = (p_pow1[i-1] * p1) % m1;
            p_pow2[i] = (p_pow2[i-1] * p2) % m2;
        }
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % m1;
            h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
        }

        int l = 1, r = n - 1;
        while (l <= r) {
            int mm = (l + r) / 2;
            unordered_set<pair<long long, long long>,pair_hash> hs;
            bool found = false;

            for (int i = 0; i <= n - mm; i++) {
                long long cur_h1 = (h1[i + mm] - h1[i] + m1) % m1;
                long long cur_h2 = (h2[i + mm] - h2[i] + m2) % m2;
                cur_h1 = (cur_h1 * p_pow1[n-i-1]) % m1;
                cur_h2 = (cur_h2 * p_pow2[n-i-1]) % m2;

                if (hs.count({cur_h1, cur_h2})) {
                    found = true;
                    if (mm > ans.size()) {
                        ans = s.substr(i, mm);
                    }
                    break;
                }
                hs.insert({cur_h1, cur_h2});
            }

            if (found) {
                l = mm + 1; 
            } else {
                r = mm - 1;  
            }
        }

        return ans;
    }
};