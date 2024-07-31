class Solution {
    int dph(vector<vector<int>>& b, int s, vector<vector<int>>& mm, int i, int rs, int mx) {
        vector<int> cb = b[i];
        int mxu = max(mx, cb[1]);
        if (i == b.size() - 1) {
            if (rs >= cb[0]) return mxu;
            return mx + cb[1];
        }
        if (mm[i][rs] != 0) {
            return mm[i][rs];
        } else {
            int op1h = mx + dph(b, s, mm, i + 1, s - cb[0], cb[1]);
            if (rs >= cb[0]) {
                int op2h = dph(b, s, mm, i + 1, rs - cb[0], mxu);
                mm[i][rs] = min(op1h, op2h);
                return mm[i][rs];
            }
            mm[i][rs] = op1h;
            return mm[i][rs];
        }
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(sw + 1, 0));
        return dph(books, sw, dp, 0, sw, 0);
    }
};
