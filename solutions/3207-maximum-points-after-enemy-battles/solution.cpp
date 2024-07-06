class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        multiset<long long>st;
        for(auto x:e){
            st.insert(x);
        }
        if(c<(*st.begin())){
            return 0;
        }
        long long ans=0;
        while(!st.empty()){
            if(c<(*st.begin()) && ans>=1){
                long long r=*(--st.end());
                st.erase(--st.end());
                c+=r;
            }
            if(c>= (*st.begin()) && !st.empty()){
                long long o=c/(*st.begin());
                
                ans+=o;
                c-=o*(*st.begin());
            }
        }
        return ans;
    }
};