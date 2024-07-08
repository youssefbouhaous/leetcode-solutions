class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }

        auto it = st.begin();
        int kk = 1;

        while (st.size() > 1) {
            if (kk == k) {
                auto tmp = it;
                if (++it == st.end()) {
                    it = st.begin();
                }
                st.erase(tmp);
                kk = 1; // Reset the counter
            } else {
                kk++;
                if (++it == st.end()) {
                    it = st.begin();
                }
            }
        }
        
        return *st.begin();
    }
};
