class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        multiset<int>st;
        for(auto x:nums){st.insert(x);}
        long long score=0;
        while(k--){
            long long tmp=(*(--st.end()));
            st.erase((--st.end()));
            score+=tmp;
            st.insert((int)(ceil(((double)tmp)/3.0)));
        }
        return score;
    }
};