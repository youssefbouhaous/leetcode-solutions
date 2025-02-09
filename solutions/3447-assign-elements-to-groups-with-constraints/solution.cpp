class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        int mx = 100000;
        vector<int> pos(mx + 1, INT_MAX);
        for (int i = 0; i < e.size(); i++) {
            pos[e[i]] = min(pos[e[i]], i);
        }
        vector<int> ans;
        for (int x : g) {
            int b = INT_MAX;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    b = min(b, pos[d]);
                    if (d * d != x) b = min(b, pos[x / d]);
                }
            }
            ans.push_back(b == INT_MAX ? -1 : b);
        }
        return ans;
    }
};
